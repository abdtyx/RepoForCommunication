#include <bits/stdc++.h>
using namespace std;

void info(char a);

typedef struct _student
{
    int num;
    double s1;
    double s2;
    double s3;
    double sum;
    double an;
} Student;

int main()
{
    Student student[3];
    Student s;
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
    if (a != 'i')
    {
        return 0;
    }
    for (int i = 0; i < 3; i++)
    {
        cin >> student[i].num >> student[i].s1 >> student[i].s2 >> student[i].s3;
        student[i].sum = student[i].s1 + student[i].s2 + student[i].s3;
        student[i].an = student[i].sum / 3;
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2 - i; j++)
        {
            if (student[j].sum > student[j + 1].sum)
            {
                s = student[j];
                student[j] = student[j + 1];
                student[j + 1] = s;
            }
        }
    }
    for (int k = 0; k < 3; k++)
    {
        cout << fixed << setprecision(1) << student[k].num << "," << student[k].sum << "," << student[k].an << endl;
    }
}

void info(char a)
{
    if (a == 'i')
    {
        cout << "Please input info of the three students:" << endl;
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
