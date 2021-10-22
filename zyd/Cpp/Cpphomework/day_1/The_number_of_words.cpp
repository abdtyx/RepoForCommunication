#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    string str;
    int i = 0;
    cin >> str;
    while (str!="done")
    {
        i++;
        cin >> str;
    }
    cout << "You entered a total of " << i << " words.";
}