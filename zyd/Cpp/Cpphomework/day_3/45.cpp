#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    getline(cin, s);
    char a[100];
    strcpy(a, s.c_str());
    int space = 0, capital = 0, lowercase = 0, number = 0;
    for (int i = 0; i < strlen(a); i++)
    {
        if (a[i] == ' ')
        {
            space++;
        }
        if (a[i] >= 'A' && a[i] <= 'Z')
        {
            capital++;
        }
        if (a[i] >= 'a' && a[i] <= 'z')
        {
            lowercase++;
        }
        if (a[i] >= '0' && a[i] <= '9')
        {
            number++;
        }
    }
    cout << "space: " << space << endl;
    cout << "capital: " << capital << endl;
    cout << "lowercase: " << lowercase << endl;
    cout << "number: " << number << endl;
}