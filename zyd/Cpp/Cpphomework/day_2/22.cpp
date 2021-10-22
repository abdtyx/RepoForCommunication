#include <bits/stdc++.h>
using namespace std;

void info(char a);

int main()
{
    cout << "                              "
         << "1.Input" << endl;
    cout << "                              "
         << "2.Output" << endl;
    cout << "                              "
         << "3.Order" << endl;
    cout << "                              "
         << "4.Quit" << endl;
    char a;
    cin >> a;
    info(a);
}


void info(char a)
{
    if (a == 'i')
    {
        cout << "You are trying to Input info" << endl;
    }
    else if (a == 'o')
    {
        cout << "You are trying to Output info" << endl;
    }
    else if (a == 'm')
    {
        cout << "You are trying to Make things ordered" << endl;
    }
    else if (a == 'q')
    {
        cout << "You are about to Quit" << endl;
    }
    else
    {
        cout << "Wrong input" << endl;
    }
}