#include <iostream>
using namespace std;
int main()
{
    int len;
    cin >> len;
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            cout << ".";
        }
        for (int k = 0; k <= i; k++)
        {
            cout << "*";
        }
        cout <<endl;
    }
}