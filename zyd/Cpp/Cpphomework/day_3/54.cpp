#include <time.h>
#include <iostream>

using namespace std;

int a[1000];
void comb(int n, int r)
{
    int i, j;
    for (i = n; i >= r; i--)
    {
        a[r] = i;
        if (r > 1)
            comb(i - 1, r - 1);
        else
        {
            for (j = a[0]; j > 0; j--)
            {
                cout << a[j];
            }
            cout << endl;
        }
    }
}

int main()
{
    int n, r;
    cin >> n >> r;
    a[0] = r;
    comb(n, r);
    return 0;
}
