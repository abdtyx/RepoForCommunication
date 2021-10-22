#include <bits/stdc++.h>
using namespace std;

typedef struct _student
{
    string id;
    int cl;
    string name;
    double s1;
    double s2;
    double s3;
    double sum;
} Student;

void info(Student student[]);
void bubble_cl(Student student[]);
void bubble_sum(Student student[]);
void output(Student student[], int n);

int main()
{
    Student student[3];
    info(student);
    string input;
    char k;
    int i = 0, flag = 0;
    cin >> input;
    for (; i < 3; i++)
    {
        if (input == student[i].id || input == student[i].name)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        for (int j = 0; j < 3; j++)
        {
            output(student, j);
        }
        return 0;
    }
    else
    {
        for (int j = 0; j < 3; j++)
        {
            if (j == i)
            {
                continue;
            }
            output(student, j);
        }
    }
    cout << "Are you sure(yes/no)?" << endl;
    cin >> k;
    if (k == 'n')
    {
        for (int j = 0; j < 3; j++)
        {
            output(student, j);
        }
    }
    if (k == 'y')
    {
        return 0;
    }
}

void output(Student student[], int n)
{
    cout << fixed << setprecision(1) << student[n].id << " " << student[n].cl << " " << student[n].name << " " << student[n].s1 << " " << student[n].s2 << " " << student[n].s3 << endl;
}

void info(Student student[])
{
    student[0].id = "10001";
    student[0].cl = 11;
    student[0].name = "Zhang";
    student[0].s1 = 99.5;
    student[0].s2 = 88.5;
    student[0].s3 = 89.5;
    student[2].id = "10002";
    student[2].cl = 12;
    student[2].name = "Yang";
    student[2].s1 = 77.9;
    student[2].s2 = 56.5;
    student[2].s3 = 87.5;
    student[1].id = "10003";
    student[1].cl = 11;
    student[1].name = "Liang";
    student[1].s1 = 92.5;
    student[1].s2 = 99.0;
    student[1].s3 = 60.5;
}