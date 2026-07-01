#include <iostream>
#include<string>
#include <ctime>
using namespace std;

class AgeCalculator {
public:
    string name;
    int birth_day, birth_month, birth_year;

    void inputDOB() {
        cout<<"Enter your Name : ";
        getline(cin,name);
        cout << "Enter your Date of Birth:\n";
        cout << "Day (1-31): ";
        cin >> birth_day;
        cout << "Month (1-12): ";
        cin >> birth_month;
        cout << "Year: ";
        cin >> birth_year;

        cout<<endl<<"Your Date of Brith :"<<birth_day<<"/"<<birth_month<<"/"<<birth_year<<endl;
    }

    void calculateAge() {
        // Get current system date
        time_t now = time(0);
        tm* ltm = localtime(&now);

        int curr_day = ltm->tm_mday;
        int curr_month = 1 + ltm->tm_mon;
        int curr_year = 1900 + ltm->tm_year;

        cout << "\nCurrent Date: " << curr_day << "/" << curr_month << "/" << curr_year << endl;

        int age_day = curr_day - birth_day;
        int age_month = curr_month - birth_month;
        int age_year = curr_year - birth_year;

        // Adjust days and months if negative
        if (age_day < 0) {
            age_month--;
            int days_in_prev_month;

            // Calculate days in previous month
            if (curr_month == 3) { // Feb case
                days_in_prev_month = (curr_year % 4 == 0 && (curr_year % 100 != 0 || curr_year % 400 == 0)) ? 29 : 28;
            } else if (curr_month == 5 || curr_month == 7 || curr_month == 10 || curr_month == 12) {
                days_in_prev_month = 30;
            } else {
                days_in_prev_month = 31;
            }

            age_day += days_in_prev_month;
        }

        if (age_month < 0) {
            age_year--;
            age_month += 12;
        }

        cout << endl <<name<< ",Still alive : " <<endl<< age_year << " Years, "
             << age_month << " Months, " << age_day << " Days \n";
    }
};

int main() {
    cout<<"Age Calculator :- ";
    AgeCalculator person;
    person.inputDOB();
    person.calculateAge();

    return 0;
}
