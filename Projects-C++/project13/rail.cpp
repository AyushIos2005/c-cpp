#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>
#include <ctime>
#include <vector>

using namespace std;

struct Train
{
    string number, name, source, destination;
    int distance;
};

struct passengerDetail
{
    string name;
    string adhara_number;
    int age;
    char gender;
    string mobile;
    string breth_presence;
    string status;
    passengerDetail *next;
};

class PNR
{
public:
    void pnr_status()
    {
        string pnr;
        cout << "\nEnter PNR Number: ";
        cin >> pnr;

        ifstream file("tickets.txt");
        string line;
        bool found = false;

        cout << "\n===== PNR STATUS =====\n";

        while (getline(file, line))
        {
            if (line.find(pnr) == 0)
            { // match PNR at start
                found = true;

                stringstream ss(line);
                string data;

                vector<string> fields;

                while (getline(ss, data, '|'))
                {
                    fields.push_back(data);
                }

                cout << "\nTrain: " << fields[1] << " - " << fields[2];
                cout << "\nFrom: " << fields[3] << " To: " << fields[4];
                cout << "\nDate: " << fields[5];

                cout << "\nPassenger: " << fields[6];
                cout << "\nAge: " << fields[7];
                cout << "\nGender: " << fields[8];
                cout << "\nSeat: " << fields[11];

                cout << "\nStatus: CONFIRMED\n";
                cout << "--------------------------\n";
            }
        }

        file.close();

        if (!found)
        {
            cout << " Invalid PNR or No Booking Found!\n";
        }
    }

    void showChart()
    {
        string trainNo;
        cout << "\nEnter Train Number: ";
        cin >> trainNo;

        ifstream file("tickets.txt");
        string line;
        bool found = false;

        cout << "\n===== TRAIN CHART =====\n";

        while (getline(file, line))
        {
            stringstream ss(line);
            vector<string> f;
            string temp;

            while (getline(ss, temp, '|'))
            {
                f.push_back(temp);
            }

            if (f[1] == trainNo)
            {
                found = true;

                cout << "\nPNR: " << f[0];
                cout << "\nName: " << f[6];
                cout << "\nAge: " << f[7];
                cout << "\nGender: " << f[8];
                cout << "\nSeat: " << f[11];
                cout << "\n----------------------";
            }
        }

        file.close();

        if (!found)
        {
            cout << "No passengers found for this train!\n";
        }
    }
};

class payment
{
private:
    double totalRevenue = 0;

public:
    double calculateFare(int distance, int cls, int passengers)
    {
        double rate = 0;

        if (cls == 1)
            rate = 0.5; // SL
        else if (cls == 2)
            rate = 1.0; // 3AC
        else if (cls == 3)
            rate = 1.5; // 2AC
        else if (cls == 4)
            rate = 2.5; // 1AC

        return distance * rate * passengers;
    }

    void showBill(double baseFare)
    {
        double gst = baseFare * 0.05;
        double total = baseFare + gst;

        cout << "\n===== PAYMENT SUMMARY =====\n";
        cout << "Base Fare: ₹" << baseFare << endl;
        cout << "GST (5%): ₹" << gst << endl;
        cout << "Total Amount: ₹" << total << endl;
    }

    void showQR(string pnr, double amount)
    {
        cout << "\nScan QR to Pay (SIMULATED)\n";
        cout << "--------------------------------\n";
        cout << "UPI ID: railsys@upi\n";
        cout << "Amount: ₹" << amount << endl;
        cout << "Reference: " << pnr << endl;
        cout << "--------------------------------\n";
    }

    void saveRevenue(string trainNo, string pnr, double amount)
    {
        ofstream file("revenue.txt", ios::app);

        file << trainNo << "|"
             << pnr << "|"
             << amount << endl;

        file.close();
    }

    void paymentProcess(string pnr, string trainNo,
                        int distance, int cls, int passengers)
    {

        double baseFare = calculateFare(distance, cls, passengers);
        double gst = baseFare * 0.05;
        double total = baseFare + gst;

        showBill(baseFare);
        showQR(pnr, total);

        cout << "\nPress 1 after payment: ";
        int confirm;
        cin >> confirm;

        if (confirm == 1)
        {
            cout << "\n Payment Successful!\n";
            saveRevenue(trainNo, pnr, total);
        }
        else
        {
            cout << "\n Payment Failed!\n";
        }
    }

    // 🔐 Admin only
    void showRevenue()
    {
        ifstream file("revenue.txt");
        string line;

        double total = 0;

        cout << "\n===== ADMIN REVENUE =====\n";

        while (getline(file, line))
        {
            stringstream ss(line);
            string train, pnr, amt;

            getline(ss, train, '|');
            getline(ss, pnr, '|');
            getline(ss, amt, '|');

            cout << "Train: " << train
                 << " PNR: " << pnr
                 << " Amount: ₹" << amt << endl;

            total += stod(amt);
        }

        cout << "\nTotal Revenue: ₹" << total << endl;

        file.close();
    }
};

class booked
{
public:
    bool isWithin2Months(string date)
    {
        int d = stoi(date.substr(0, 2));
        int m = stoi(date.substr(2, 2));
        int y = stoi(date.substr(4, 4));

        tm input = {};
        input.tm_mday = d;
        input.tm_mon = m - 1;
        input.tm_year = y - 1900;

        time_t input_time = mktime(&input);
        time_t now = time(0);

        double diff = difftime(input_time, now) / (60 * 60 * 24);

        return (diff >= 0 && diff <= 60);
    }
    vector<Train> loadTrains()
    {
        vector<Train> trains;
        ifstream file("trains_cleartips.csv");
        string line;

        getline(file, line); // skip header

        while (getline(file, line))
        {
            stringstream ss(line);
            Train t;

            string temp;

            getline(ss, t.number, ',');
            getline(ss, t.name, ',');
            getline(ss, t.source, ',');
            getline(ss, t.destination, ',');
            getline(ss, temp, ',');

            t.distance = stoi(temp);

            trains.push_back(t);
        }

        return trains;
    }

    // 🔹 Price logic
    void showPrices(int dist)
    {
        cout << "SL  : ₹" << dist * 0.5 << endl;
        cout << "3AC : ₹" << dist * 1.0 << endl;
        cout << "2AC : ₹" << dist * 1.5 << endl;
        cout << "1AC : ₹" << dist * 2.5 << endl;
    }

    string getBerthType(int seatNo)
    {
        int x = (seatNo - 1) % 8 + 1;

        if (x == 1 || x == 4)
            return "LB";
        if (x == 2 || x == 5)
            return "MB";
        if (x == 3 || x == 6)
            return "UB";
        if (x == 7)
            return "SL";
        if (x == 8)
            return "SU";

        return "";
    }

    // 🔹 Step 3
    void booking_ticket_step3(string source, string des, string date,
                              string number, string name, int distance)
    {

        cout << "\n===== Ticket Booking Step 3 =====\n";

        cout << "From: " << source << "  To: " << des << endl;
        cout << "Train: " << number << " - " << name << endl;

        // 🔹 Select Class
        int cls;
        cout << "\nSelect Class:\n";
        cout << "1. Sleeper (SL)\n2. 3AC\n3. 2AC\n4. 1AC\n";
        cout << "Enter choice: ";
        cin >> cls;

        // 🔹 Number of passengers
        int n;
        cout << "Enter number of passengers: ";
        cin >> n;

        passengerDetail *head = NULL;
        passengerDetail *temp = NULL;

        // 🔹 Seat system
        int maxSeats = 0;
        string coachPrefix;
        int coachCount = 0;

        if (cls == 1)
        { // Sleeper
            coachPrefix = "S";
            coachCount = 8; // S1–S8
        }
        else if (cls == 2)
        { // 3AC
            coachPrefix = "B";
            coachCount = 6; // B1–B6
        }
        else if (cls == 3)
        { // 2AC (your custom)
            coachPrefix = "B";
            coachCount = 6; // B7–B12 (custom)
        }
        else if (cls == 4)
        { // 1AC
            coachPrefix = "A";
            coachCount = 3; // A1–A3
        }
        else
        {
            cout << "Invalid class!\n";
            return;
        }

        maxSeats = coachCount * 72;

        if (n > maxSeats)
        {
            cout << "\n Sorry! Train is fully booked.\n";
            return;
        }

        // 🔹 Passenger Input + Seat Allocation
        int bookedSeats = getBookedSeats(number, date);
        int currentSeat = bookedSeats + 1;

        for (int i = 0; i < n; i++)
        {

            passengerDetail *p = new passengerDetail();

            cout << "\nPassenger " << i + 1 << " Name: ";
            cin >> p->name;

            cout << "Age: ";
            cin >> p->age;

            cout << "Gender (M/F/T): ";
            cin >> p->gender;

            cout << "Aadhaar: ";
            cin >> p->adhara_number;

            cout << "Mobile: ";
            cin >> p->mobile;

            // 🔹 Seat Logic
            int coachNo = (currentSeat - 1) / 72 + 1;
            int seatNo = (currentSeat - 1) % 72 + 1;

            string coach;

            if (cls == 3) // custom B7–B12
                coach = "B" + to_string(coachNo + 6);
            else
                coach = coachPrefix + to_string(coachNo);

            string berth = getBerthType(seatNo);
            p->breth_presence = coach + "-" + to_string(seatNo) + " (" + berth + ")";
            currentSeat++;

            // 🔹 Linked list insert
            p->next = NULL;

            if (head == NULL)
                head = p;
            else
                temp->next = p;

            temp = p;
        }

        // 🔹 Show Ticket Summary
        cout << "\n===== BOOKING CONFIRMED =====\n";

        passengerDetail *cur = head;
        int count = 1;

        while (cur != NULL)
        {
            cout << "\nPassenger " << count++ << endl;
            cout << "Name: " << cur->name << endl;
            cout << "Seat: " << cur->breth_presence << endl;

            cur = cur->next;
        }

        // 🔹 Generate PNR
        string pnr = "PNR" + to_string(rand() % 1000000);

        cout << "\nPNR: " << pnr << endl;
        cout << "Status: CONFIRMED\n";
        // PNR prn;
        // prn.pnr_status(status_code)

        savePassengers(head, pnr, number, name, source, des, date);
        payment p1;
        p1.paymentProcess(pnr, number, distance, cls, n);
    }
    void show_trains(string source, string des, string date)
    {

        if (!isWithin2Months(date))
        {
            cout << "X Booking allowed only within next 60 days!\n";
            return;
        }

        vector<Train> trains = loadTrains();
        vector<Train> matched; // ✅ store matching trains

        cout << "\nAvailable Trains:\n";

        for (auto t : trains)
        {
            if (t.source == source && t.destination == des)
            {

                matched.push_back(t); // ✅ store train

                cout << "\n----------------------------\n";
                cout << "Train No: " << t.number << endl;
                cout << "Name    : " << t.name << endl;
                cout << "Distance: " << t.distance << " km\n";

                showPrices(t.distance);
            }
        }

        if (matched.empty())
        {
            cout << "X No trains found!\n";
            return;
        }

        string choice;
        cout << "\nSelect Train (enter train number): ";
        cin >> choice;

        // ✅ find selected train
        for (auto t : matched)
        {
            if (t.number == choice)
            {

                cout << "\n Train Selected: " << t.number << endl;

                booking_ticket_step3(source, des, date, t.number, t.name, t.distance);
                return;
            }
        }

        cout << "Invalid train number!\n";
    }

    void savePassengers(passengerDetail *head, string pnr,
                        string trainNo, string trainName,
                        string source, string dest, string date)
    {

        ofstream file("tickets.txt", ios::app);

        passengerDetail *temp = head;

        while (temp != NULL)
        {
            file << pnr << "|"
                 << trainNo << "|"
                 << trainName << "|"
                 << source << "|"
                 << dest << "|"
                 << date << "|"
                 << temp->name << "|"
                 << temp->age << "|"
                 << temp->gender << "|"
                 << temp->adhara_number << "|"
                 << temp->mobile << "|"
                 << temp->breth_presence
                 << endl;

            temp = temp->next;
        }

        file.close();
    }
    int getBookedSeats(string trainNo, string date)
    {
        ifstream file("tickets.txt");
        string line;
        int count = 0;

        while (getline(file, line))
        {
            stringstream ss(line);
            vector<string> f;
            string temp;

            while (getline(ss, temp, '|'))
                f.push_back(temp);

            if (f.size() > 5 && f[1] == trainNo && f[5] == date)
            {
                if (f[11] != "NA") // confirmed seat
                    count++;
            }
        }
        return count;
    }
};

class rail
{
private:
    string username = "admin";
    string password = "admin@212169";

public:
    string get_user_random()
    {
        string user;
        bool exists;

        do
        {
            exists = false;
            user = "user" + to_string(rand() % 100000);

            ifstream file("users.txt");
            string line;

            while (getline(file, line))
            {
                int pos = line.find('|');
                string f_user = line.substr(0, pos);

                if (f_user == user)
                {
                    exists = true;
                    break;
                }
            }

            file.close();

        } while (exists);

        return user;
    }
    void new_user()
    {
        int pin_code;
        string user;
        string pass, confirm_pass;
        string name, address, mobile, adhar_number, email;
        string dist, landmark, state;

        cout << "Welcome to RailSyS\n";
        cout << "Disclaimer: Avoid unwanted content.\n\n";

        cin.ignore();

        cout << "1. Enter your full name: ";
        getline(cin, name);

        cout << "2. Enter your mobile number: ";
        getline(cin, mobile);

        cout << "3. Enter your landmark: ";
        getline(cin, landmark);

        cout << "4. Enter your address: ";
        getline(cin, address);

        cout << "5. Enter your pin-code: ";
        cin >> pin_code;
        cin.ignore();

        cout << "6. Enter your district: ";
        getline(cin, dist);

        cout << "7. Enter your state: ";
        getline(cin, state);

        cout << "8. Enter your email: ";
        getline(cin, email);

        cout << "9. Enter your Aadhaar number: ";
        getline(cin, adhar_number);

        cout << "10. Create password: ";
        getline(cin, pass);

        cout << "11. Confirm password: ";
        getline(cin, confirm_pass);

        if (pass != confirm_pass)
        {
            cout << "X Passwords do not match!\n";
            return;
        }

        string rand_user = get_user_random();
        cout << "\n Your username: " << rand_user << endl;

        // Save to file
        ofstream file("users.txt", ios::app);

        file << rand_user << "|"
             << name << "|"
             << mobile << "|"
             << landmark << "|"
             << address << "|"
             << pin_code << "|"
             << dist << "|"
             << state << "|"
             << email << "|"
             << adhar_number << "|"
             << pass << endl;

        file.close();

        cout << "\n🎉 Registration Successful!\n";
        login();
    }
    void login()
    {
        string user, pass;

        cout << "Enter username: ";
        cin >> user;
        cout << "Enter password: ";
        cin >> pass;

        // 🔹 Check admin first
        if (user == username && pass == password)
        {
            cout << "Welcome Admin!!\n";
            return;
        }

        // 🔹 Check file users
        ifstream file("users.txt");
        string line;
        bool found = false;

        while (getline(file, line))
        {
            // split by '|'
            int pos1 = line.find('|');
            int pos_last = line.rfind('|');

            string f_user = line.substr(0, pos1);
            string f_pass = line.substr(pos_last + 1);

            if (user == f_user && pass == f_pass)
            {
                found = true;
                break;
            }
        }
        file.close();

        if (found)
        {
            cout << "Login Successful!\n";
            ticket_booking_step1();
        }
        else
        {
            cout << "Invalid Username or Password!\n";
            return;
        }
    }
    void has_login_req()
    {
        int choice;
        cout << "Press 1 for Login" << endl;
        cout << "Press 2 for New User" << endl;
        cout << "Enter Your Choice : " << endl;
        cin >> choice;
        if (choice == 1 || choice == 2)
        {
            switch (choice)
            {
            case 1:
                login();
                break;
            case 2:
                new_user();
                break;
            default:
                cout << "Enter Correct choice" << endl;
                break;
            }
        }
        else
        {
            cout << "Access Denined!!";
        }
    }
    void ticket_booking_step1()
    {
        string source;
        string des;
        string dd_mm_yyyy;
        int qota;
        cout << "Enter a Source Station/Station Code : ";
        getline(cin, source);
        cout << "Enter a destination Station/Station code : ";
        getline(cin, des);
        cout << "Enter a date(in ddmmyyyy): ";
        getline(cin, dd_mm_yyyy);
        cout << "Select Qoute" << endl;

        cout << "1.GENERAL\n2.LADIES\n3.LOWER BERTH/SR.CITIZEN\n4.PERSON WITH DISABILITY\n5.DUTY PASS\n6.TATKAL\n7.PREMIUM TATKAL" << endl;
        cout << "Enter a Qoute : ";
        // getline(cin,qota);
        cin >> qota;
        booked b1;
        // cout<<"Enter a choice : ";
        if (source == des)
        {
            cout << "Error: Source and Destination cannot be same!\n";
            return;
        }

        // Show selection
        cout << "\nBoarding: " << source
             << "  Destination: " << des
             << "  Date: " << dd_mm_yyyy << endl;

        // Handle quota
        switch (qota)
        {
        case 1:
            cout << "Quota: GENERAL\n";
            break;
        case 2:
            cout << "Quota: LADIES\n";
            break;
        case 3:
            cout << "Quota: SR.CITIZEN\n";
            break;
        case 4:
            cout << "Quota: DISABILITY\n";
            break;
        case 5:
            cout << "Quota: DUTY PASS\n";
            break;
        case 6:
            cout << "Quota: TATKAL\n";
            break;
        case 7:
            cout << "Quota: PREMIUM TATKAL\n";
            break;
        default:
            cout << "Invalid quota!\n";
            return;
        }

        // Show trains
        b1.show_trains(source, des, dd_mm_yyyy);
    }
};

int main()
{
    rail r1;
    PNR p;
    cout << "Welcome to RailSyS System" << endl;

    cout << "==================================================================";
    cout << "||\t\t\t\t\t\t\t||" << endl;
    cout << "||\t\t\t\t\t\t\t||" << endl;
    cout << "||\t\t\tPress 1 for Login\t\t\t\t||" << endl;
    cout << "||\t\t\tPress 2 for PNR Status\t\t\t\t||" << endl;
    cout << "||\t\t\tPress 3 for Chart\t\t\t\t||" << endl;
    cout << "||\t\t\tPress 4 for Exit\t\t\t\t||" << endl;
    cout << "||\t\t\t\t\t\t\t||" << endl;
    cout << "||\t\t\t\t\t\t\t||" << endl;
    cout << "==================================================================";
    int choice;
    cout << "||\t\tEnter Your Choice : \t\t\t\t\t\t||";
    cin >> choice;
    cout << "==================================================================";
    switch (choice)
    {
    case 1:
        /* code */
        r1.has_login_req();
        break;
    case 2:
        p.pnr_status();
        break;
    case 3:
        p.showChart();
        break;
    case 4:
        cout << "Exiting....";
        exit(0);
    default:
        cout << "Try Again!!";
        break;
    }

    return 0;
}