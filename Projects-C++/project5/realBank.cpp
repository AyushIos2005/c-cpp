// BankSystem.cpp
#include <bits/stdc++.h>
using namespace std;

struct Account {
    long long accNo;
    int pin; // 4-digit
    string name;
    string fname;
    string cnic;
    string phone;
    string email;
    double balance;
};

const string DB_FILE = "BankData.txt";
const string TX_FILE = "Transactions.txt";

// Helpers
string nowTimestamp() {
    time_t t = time(nullptr);
    tm local_tm = *localtime(&t);
    char buf[64];
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", &local_tm);
    return string(buf);
}

long long generateAccountNumber() {
    // Use time + rand to reduce collisions
    long long t = static_cast<long long>(time(nullptr));
    int r = rand() % 9000 + 1000; // 4-digit random
    // combine (t % 1e9) to keep it reasonable
    long long acc = (t % 1000000000LL) * 10000LL + r;
    return acc;
}

// File parsing: each record as: accNo|pin|name|fname|cnic|phone|email|balance
vector<Account> readAllAccounts() {
    vector<Account> all;
    ifstream fin(DB_FILE);
    if (!fin) return all; // file may not exist yet
    string line;
    while (getline(fin, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        Account a;
        string token;
        // accNo
        if (!getline(ss, token, '|')) continue;
        a.accNo = stoll(token);
        // pin
        if (!getline(ss, token, '|')) continue;
        a.pin = stoi(token);
        // name
        if (!getline(ss, a.name, '|')) continue;
        // fname
        if (!getline(ss, a.fname, '|')) continue;
        // cnic
        if (!getline(ss, a.cnic, '|')) continue;
        // phone
        if (!getline(ss, a.phone, '|')) continue;
        // email
        if (!getline(ss, a.email, '|')) continue;
        // balance
        if (!getline(ss, token, '|')) continue;
        a.balance = stod(token);
        all.push_back(a);
    }
    fin.close();
    return all;
}

bool writeAllAccounts(const vector<Account>& all) {
    ofstream fout("temp_db.txt", ios::out | ios::trunc);
    if (!fout) return false;
    for (const auto &a : all) {
        fout << a.accNo << '|' << a.pin << '|' << a.name << '|' << a.fname << '|'
             << a.cnic << '|' << a.phone << '|' << a.email << '|' << fixed << setprecision(2) << a.balance << '\n';
    }
    fout.close();
    // replace
    remove(DB_FILE.c_str());
    rename("temp_db.txt", DB_FILE.c_str());
    return true;
}

void appendTransaction(long long accNo, const string &type, double amount, double balanceAfter) {
    ofstream fout(TX_FILE, ios::out | ios::app);
    if (!fout) return;
    fout << accNo << '|' << nowTimestamp() << '|' << type << '|' << fixed << setprecision(2)
         << amount << '|' << balanceAfter << '\n';
    fout.close();
}

// UI / Operations
void createAccount() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    Account a;
    srand((unsigned)time(nullptr) ^ (unsigned)clock());
    a.accNo = generateAccountNumber();

    cout << "\n=== Create New Account ===\n";
    cout << "Enter Name: ";
    getline(cin, a.name);
    cout << "Enter Father's Name: ";
    getline(cin, a.fname);
    cout << "Enter CNIC: ";
    getline(cin, a.cnic);
    cout << "Enter Phone: ";
    getline(cin, a.phone);
    cout << "Enter Email: ";
    getline(cin, a.email);

    cout << "Enter Opening Balance: ";
    while (!(cin >> a.balance) || a.balance < 0) {
        cout << "Invalid amount. Enter a non-negative number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Create a 4-digit PIN (0000 - 9999): ";
    while (!(cin >> a.pin) || a.pin < 0 || a.pin > 9999) {
        cout << "Invalid PIN. Enter a 4-digit PIN: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Save account
    vector<Account> all = readAllAccounts();
    all.push_back(a);
    if (!writeAllAccounts(all)) {
        cout << "Error: Unable to save account data.\n";
        return;
    }
    appendTransaction(a.accNo, "OPEN", a.balance, a.balance);

    cout << "\nAccount created successfully!\n";
    cout << "Your Account Number: " << a.accNo << "\n";
    cout << "Please save your Account Number and PIN securely.\n";
}

Account* findAccount(vector<Account>& all, long long accNo) {
    for (auto &a : all) {
        if (a.accNo == accNo) return &a;
    }
    return nullptr;
}

void showProfile(const Account &a) {
    cout << "\n--- Profile ---\n";
    cout << "Account No: " << a.accNo << '\n';
    cout << "Name      : " << a.name << '\n';
    cout << "Father    : " << a.fname << '\n';
    cout << "CNIC      : " << a.cnic << '\n';
    cout << "Phone     : " << a.phone << '\n';
    cout << "Email     : " << a.email << '\n';
    cout << "Balance   : " << fixed << setprecision(2) << a.balance << '\n';
}

void depositAmount(Account &a, vector<Account>& all) {
    double amt;
    cout << "Enter amount to deposit: ";
    while (!(cin >> amt) || amt <= 0) {
        cout << "Enter a positive amount: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    a.balance += amt;
    writeAllAccounts(all);
    appendTransaction(a.accNo, "DEPOSIT", amt, a.balance);
    cout << "Deposit successful. New balance: " << fixed << setprecision(2) << a.balance << '\n';
}

void withdrawAmount(Account &a, vector<Account>& all) {
    double amt;
    cout << "Enter amount to withdraw: ";
    while (!(cin >> amt) || amt <= 0) {
        cout << "Enter a positive amount: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    if (amt > a.balance) {
        cout << "Insufficient balance. Available: " << fixed << setprecision(2) << a.balance << '\n';
        return;
    }
    a.balance -= amt;
    writeAllAccounts(all);
    appendTransaction(a.accNo, "WITHDRAW", amt, a.balance);
    cout << "Withdrawal successful. New balance: " << fixed << setprecision(2) << a.balance << '\n';
}

void updateDetails(Account &a, vector<Account>& all) {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "\n--- Update Details (leave blank to keep current) ---\n";
    cout << "Current Name: " << a.name << "\nNew Name: ";
    string tmp; getline(cin, tmp); if (!tmp.empty()) a.name = tmp;

    cout << "Current Father's Name: " << a.fname << "\nNew Father's Name: ";
    getline(cin, tmp); if (!tmp.empty()) a.fname = tmp;

    cout << "Current CNIC: " << a.cnic << "\nNew CNIC: ";
    getline(cin, tmp); if (!tmp.empty()) a.cnic = tmp;

    cout << "Current Phone: " << a.phone << "\nNew Phone: ";
    getline(cin, tmp); if (!tmp.empty()) a.phone = tmp;

    cout << "Current Email: " << a.email << "\nNew Email: ";
    getline(cin, tmp); if (!tmp.empty()) a.email = tmp;

    writeAllAccounts(all);
    cout << "Details updated successfully.\n";
}

void showTransactionHistory(long long accNo) {
    ifstream fin(TX_FILE);
    if (!fin) {
        cout << "No transactions found.\n";
        return;
    }
    cout << "\n--- Transaction History for " << accNo << " ---\n";
    string line;
    bool found = false;
    while (getline(fin, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string t_acc, ts, type, amt, bal;
        if (!getline(ss, t_acc, '|')) continue;
        if (stoll(t_acc) != accNo) continue;
        getline(ss, ts, '|');
        getline(ss, type, '|');
        getline(ss, amt, '|');
        getline(ss, bal, '|');
        cout << ts << " | " << setw(8) << type << " | Amount: " << amt << " | Balance: " << bal << '\n';
        found = true;
    }
    fin.close();
    if (!found) cout << "No transactions for this account.\n";
}

void deleteAccount(vector<Account>& all) {
    cout << "Enter Account Number to delete: ";
    long long acc;
    if (!(cin >> acc)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input.\n";
        return;
    }
    auto it = remove_if(all.begin(), all.end(), [&](const Account &a){ return a.accNo == acc; });
    if (it == all.end()) {
        cout << "Account not found.\n";
        return;
    }
    bool existed = (it != all.end());
    all.erase(it, all.end());
    writeAllAccounts(all);
    appendTransaction(acc, "DELETE", 0.0, 0.0);
    cout << "Account deleted (if existed) and data saved.\n";
}

void listAllAccounts() {
    vector<Account> all = readAllAccounts();
    if (all.empty()) {
        cout << "No accounts to show.\n";
        return;
    }
    cout << "\n--- All Accounts ---\n";
    cout << left << setw(18) << "AccountNo" << setw(8) << "PIN" << setw(16) << "Name" << setw(16) << "Phone" << setw(12) << "Balance" << '\n';
    cout << string(70, '-') << '\n';
    for (const auto &a : all) {
        cout << left << setw(18) << a.accNo << setw(8) << setfill('0') << setw(4) << a.pin << setfill(' ') 
             << setw(16) << a.name << setw(16) << a.phone << setw(12) << fixed << setprecision(2) << a.balance << '\n';
    }
}

// Login + user session
void userSession(Account &a) {
    vector<Account> all = readAllAccounts();
    Account *ptr = findAccount(all, a.accNo);
    if (!ptr) { cout << "Internal error. Account not found.\n"; return; }

    while (true) {
        cout << "\n=== Account Menu for " << a.accNo << " ===\n";
        cout << "1. Show Profile\n2. Check Balance\n3. Deposit\n4. Withdraw\n5. Update Details\n6. Transaction History\n7. Logout\n";
        cout << "Enter choice: ";
        int ch; if (!(cin >> ch)) { cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); continue; }
        // reload accounts each time to keep pointer reference accurate
        vector<Account> fresh = readAllAccounts();
        Account *cur = findAccount(fresh, a.accNo);
        if (!cur) { cout << "Your account no longer exists.\n"; return; }
        switch (ch) {
            case 1: showProfile(*cur); break;
            case 2: cout << "Current Balance: " << fixed << setprecision(2) << cur->balance << '\n'; break;
            case 3: depositAmount(*cur, fresh); break;
            case 4: withdrawAmount(*cur, fresh); break;
            case 5: updateDetails(*cur, fresh); break;
            case 6: showTransactionHistory(cur->accNo); break;
            case 7: cout << "Logging out...\n"; return;
            default: cout << "Invalid choice.\n";
        }
        // after operations, persist fresh back to disk
        writeAllAccounts(fresh);
    }
}

void loginAndSession() {
    cout << "\nEnter Account Number: ";
    long long acc; if (!(cin >> acc)) { cout << "Invalid input.\n"; cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); return; }
    cout << "Enter PIN: ";
    int pin; if (!(cin >> pin)) { cout << "Invalid input.\n"; cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); return; }

    vector<Account> all = readAllAccounts();
    Account *a = findAccount(all, acc);
    if (!a) {
        cout << "Account not found.\n";
        return;
    }
    if (a->pin != pin) {
        cout << "Incorrect PIN.\n";
        return;
    }
    cout << "Login successful. Welcome, " << a->name << "!\n";
    userSession(*a);
}

int main() {
    srand((unsigned)time(nullptr));
    cout << "Welcome to Verma's Bank\nYour Trusted Bank Partner\n";

    while (1) {
        cout << "\n===== Main Menu =====\n";
        cout << "1. Create Account\n2. Login to Account\n3. Delete Account\n4. List All Accounts (Admin view)\n5. Exit\n";
        cout << "Enter choice: ";
        int choice; if (!(cin >> choice)) {
            cout << "Invalid input.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        switch (choice) {
            case 1: createAccount(); break;
            case 2: loginAndSession(); break;
            case 3: {
                vector<Account> all = readAllAccounts();
                deleteAccount(all);
            } break;
            case 4: listAllAccounts(); break;
            case 5: cout << "Goodbye!\n"; return 0;
            default: cout << "Invalid choice.\n";
        }
    }
    return 0;
}
