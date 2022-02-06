#include <bits/stdc++.h>
using namespace std;

typedef struct _number
{
    int local[2];
    int number[2];
    int min;
} Num;

int main()
{
    int *a1, n, sum, m = 0;
    cin >> n;
    a1 = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a1[i];
    }
    cin >> sum;
    Num num[20];
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a1[i] + a1[j] == sum)
            {
                num[m].local[0] = i;
                num[m].local[1] = j;
                num[m].number[0] = a1[i];
                num[m].number[1] = a1[j];
                a1[i] > a1[j] ? num[m].min = a1[j] : num[m].min = a1[i];
                m++;
            }
        }
    }
    for (int i = 0; i < m - 1; i++)
    {
        for (int k = 0; k < m - 1 - i; k++)
        {
            if (num[k].min > num[k + 1].min)
            {
                int c = num[k].min;
                num[k].min = num[k + 1].min;
                num[k + 1].min = c;
            }
        }
    }
    cout<<"["<<num[0].local[0]<<","<<num[0].local[1]<<"]"<<endl;
}