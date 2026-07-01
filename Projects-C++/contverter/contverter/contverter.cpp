#include<iostream>
#include<string>
#include<cpprest/http_client.h>




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

	cout<<"Enter an amount : ";
	cin>>amount;
	cout<<"From : ";
	cin>>from;
	cout<<"To : ";
	cin>>to;

	http_client client(U(" https://v6.exchangerate-api.com/v6/21add8252d4692c9f7987a94/latest/USD"));
	uri_builder builder(U("/convert"));
	builder.append_query(U("to"),utility::conversions::to_string_t(to));
	builder.append_query(U("from"), utility::conversions::to_string_t(from));
	builder.append_query(U("amount"), utility::conversions::to_string_t(amount));

	builder.append_query(U("apikey"),U(" 21add8252d4692c9f7987a94"));

	http_request request(method::GET);
	request.set_request_uri(builder.to_string);


	client.request(request).then([](http_response response) {
		return response.extact_json();
		}).then([](web::json::value) {
			cout<<"\tRate : "<<body[U("info")][U("rate")].as_double();

			}).wait();

			cout<<" "<<to;







}

