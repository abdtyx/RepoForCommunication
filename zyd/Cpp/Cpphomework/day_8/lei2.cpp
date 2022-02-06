#include <bits/stdc++.h>
using namespace std;
class Bank
{
public:
    string name;
    string account_number;
    int balance;
};

int main()
{
    Bank bank;
    int sum;
    bank.balance = 0;
    cin >> sum;
    bank.balance = bank.balance + sum;
    cout << bank.balance << endl;
    cin >> sum;
    bank.balance = bank.balance + sum;
    cout << bank.balance << endl;
    cin >> sum;
    if (sum > bank.balance)
    {
        cout << "no enough balance!";
    }
    else
    {
        cout << bank.balance - sum;
    }
}