#include <iostream>
using namespace std;
int FindSmallestSum(int *a1, int *a2, int n)
{
    int min;
    min = a1[0] + a2[0];
    if (n == 0)
    {
        return 0;
    }
    else
    {
        for (int j = 1; j < n; j++)
        {
            if (min > a1[j] + a2[j])
            {
                min = a1[j] + a2[j];
            }
        }
        return min;
    }
}

int main(int argc, char const *argv[])
{
    int n;
    int *a1;
    int *a2;
    cin >> n;
    a1 = new int[n];
    a2 = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a1[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> a2[i];
    }
    cout << FindSmallestSum(a1, a2, n) << endl;
    return 0;
}