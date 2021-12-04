#include <bits/stdc++.h>

#ifndef debug
#define debug false
#endif

using namespace std;

class bank_account {
    private:
        string deposistor_name;
        string account_number;
        double balance;
    public:
        bank_account(string name, string number);
        ~bank_account();
        void display();
        double deposite(double data);
        double withdraw(double data);
};

bank_account::bank_account(string name, string number) {
    deposistor_name = name;
    account_number = number;
    balance = 0;
}

bank_account::~bank_account() {
    // do nothing
    // bool debug = false;
    if (debug) {
        cout << "Today is a nice day!";
    }
}

void bank_account::display() {
    if (debug) {
        cout << deposistor_name << ' ' << account_number << endl;
    }
    cout << balance << endl;
}

double bank_account::deposite(double data) {
    if (data >= 0 && balance >= 0) {
        balance += data;
        return balance;
    }
    else {
        return -1;
    }
}

double bank_account::withdraw(double data) {
    if (data >= 0 && balance >= 0 && balance - data >= 0) {
        balance -= data;
        return balance;
    }
    else {
        // balance = -1;
        return -1;
    }
}

int main() {
    bank_account accounter1("Mike", "10001");
    // bank_account accounter2("Jack", "10002");
    double x;
    cin >> x;
    cout << accounter1.deposite(x) << endl;
    cin >> x;
    cout << accounter1.deposite(x) << endl;
    cin >> x;
    double deb = accounter1.withdraw(x);
    if (deb == -1) {
        cout << "no enough balance!" << endl;
    }
    else {
        cout << deb << endl;
    }
    return 0;
}