#include <iostream>
#include <string>
#include <cpprest/http_client.h>
#include <cpprest/json.h>

using namespace std;
using namespace web;
using namespace web::http;
using namespace web::http::client;

int main() {
	cout << "#----------------------------------------#" << endl;
	cout << "\t\tCurrency Converter" << endl;
	cout << "#----------------------------------------#" << endl;

	string amount;
	string from;
	string to;

	cout << "Enter an amount : ";
	cin >> amount;
	cout << "From : ";
	cin >> from;
	cout << "To : ";
	cin >> to;

	// Base client URL (no leading spaces)
	http_client client(U("https://v6.exchangerate-api.com/v6/21add8252d4692c9f7987a94"));

	// Build path: /pair/{from}/{to}/{amount}
	uri_builder builder;
	builder.append_path(U("pair"));
	builder.append_path(utility::conversions::to_string_t(from));
	builder.append_path(utility::conversions::to_string_t(to));
	builder.append_path(utility::conversions::to_string_t(amount));

	try {
		client.request(methods::GET, builder.to_string())
			.then([](http_response response) {
				return response.extract_json();
			}).then([](web::json::value body) {
				if (body.has_field(U("conversion_rate"))) {
					cout << "\tRate : " << body[U("conversion_rate")].as_double() << endl;
				}
				if (body.has_field(U("conversion_result"))) {
					if (body[U("conversion_result")].is_number()) {
						cout << "\tConverted : " << body[U("conversion_result")].as_double() << endl;
					} else {
						cout << "\tConverted : " << utility::conversions::to_utf8string(body[U("conversion_result")].serialize()) << endl;
					}
				} else {
					cout << "Response: " << utility::conversions::to_utf8string(body.serialize()) << endl;
				}
			}).wait();
	}
	catch (const std::exception &e) {
		cerr << "Request failed: " << e.what() << endl;
	}

	return 0;
}



