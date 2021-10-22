#include <bits/stdc++.h>
using namespace std;

typedef struct _student
{
    int num;
    double s1;
    double s2;
    double s3;
    double sum;
} Student;

int main()
{
    Student student[3];
    for (int i = 0; i < 3; i++)
    {
        cin >> student[i].num >> student[i].s1 >> student[i].s2 >> student[i].s3;
        student[i].sum = student[i].s1 + student[i].s2 + student[i].s3;
    }
    for (int j = 0; j < 3; j++)
    {
        cout << fixed << setprecision(1) << student[j].num << "  " << student[j].s1 << "  " << student[j].s2 << "  " << student[j].s3 << "  " << student[j].sum << endl;
    }
}