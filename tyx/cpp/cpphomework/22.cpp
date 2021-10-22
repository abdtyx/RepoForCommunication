#include <bits/stdc++.h>
using namespace std;

int main() {
    string out[4] = {"1.Input", "2.Output", "3.Order", "4.Quit"};
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 30; j++) {
            cout << " ";
        }
        cout << out[i] << endl;
    }
    char in;
    cin >> in;
    switch (in)
    {
    case 'i':
        /* code */
        cout << "You are trying to Input info";
        break;
    case 'o':
        cout << "You are trying to Output info";
        break;
    case 'm':
        cout << "You are trying to Make things ordered";
        break;
    case 'q':
        cout << "You are about to Quit";
        break;
    default:
        cout << "Wrong input";
        break;
    }
}