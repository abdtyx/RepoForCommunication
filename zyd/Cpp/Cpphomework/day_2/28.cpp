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
    double put = 0;
} Student;

void info(Student student[]);
void bubble_cl(Student student[]);
void bubble_sum(Student student[]);
void output(Student student[]);

int main()
{
    Student student[3];
    Student s;
    info(student);
    int flag = 0;
    cin >> s.id >> s.cl >> s.name >> s.s1 >> s.s2 >> s.s3;
    s.sum = s.s1 + s.s2 + s.s3;
    for (int k = 0; k < 3; k++)
    {
        student[k].sum = student[k].s1 + student[k].s2 + student[k].s3;
    }
    for (int i = 0; i < 3; i++)
    {
        if (s.id == student[i].id)
        {
            student[i] = s;
            flag = 1;
            student[i].put = 1;
        }
    }
    bubble_cl(student);
    bubble_sum(student);
    output(student);
}

void output(Student student[])
{
    if (student[0].put == 1)
    {
        cout << fixed << setprecision(1) << student[0].cl << " " << student[0].id << " " << student[0].name << " " << student[0].s1 << " " << student[0].s2 << " " << student[0].s3 << " modified" << endl;
    }
    else
    {
        cout << fixed << setprecision(1) << student[0].cl << " " << student[0].id << " " << student[0].name << " " << student[0].s1 << " " << student[0].s2 << " " << student[0].s3 << endl;
    }
    if (student[1].cl == student[0].cl)
    {
        if (student[1].put == 1)
        {
            cout << fixed << setprecision(1) << "   " << student[1].id << " " << student[1].name << " " << student[1].s1 << " " << student[1].s2 << " " << student[1].s3 << " modified" << endl;
        }
        else
        {
            cout << fixed << setprecision(1) << "   " << student[1].id << " " << student[1].name << " " << student[1].s1 << " " << student[1].s2 << " " << student[1].s3 << endl;
        }
    }
    else
    {
        if (student[1].put == 1)
        {
            cout << fixed << setprecision(1) << student[1].cl << " " << student[1].id << " " << student[1].name << " " << student[1].s1 << " " << student[1].s2 << " " << student[1].s3 << " modified" << endl;
        }
        else
        {
            cout << fixed << setprecision(1) << student[1].cl << " " << student[1].id << " " << student[1].name << " " << student[1].s1 << " " << student[1].s2 << " " << student[1].s3 << endl;
        }
    }
    if (student[1].cl == student[2].cl)
    {
        if (student[2].put == 1)
        {
            cout << fixed << setprecision(1) << "   " << student[2].id << " " << student[2].name << " " << student[2].s1 << " " << student[2].s2 << " " << student[2].s3 << " modified" << endl;
        }
        else
        {
            cout << fixed << setprecision(1) << "   " << student[2].id << " " << student[2].name << " " << student[2].s1 << " " << student[2].s2 << " " << student[2].s3 << endl;
        }
    }
    else
    {
        if (student[2].put == 1)
        {
            cout << fixed << setprecision(1) << student[2].cl << " " << student[2].id << " " << student[2].name << " " << student[2].s1 << " " << student[2].s2 << " " << student[2].s3 << " modified" << endl;
        }
        else
        {
            cout << fixed << setprecision(1) << student[2].cl << " " << student[2].id << " " << student[2].name << " " << student[2].s1 << " " << student[2].s2 << " " << student[2].s3 << endl;
        }
    }
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

void bubble_cl(Student student[])
{
    Student s;
    for (int a = 0; a < 3; a++)
    {
        for (int b = 0; b < 3 - a; b++)
        {
            if (student[b].cl > student[b + 1].cl)
            {
                s = student[b];
                student[b] = student[b + 1];
                student[b + 1] = s;
            }
        }
    }
}

void bubble_sum(Student student[])
{
    Student k;
    for (int c = 0; c < 3; c++)
    {
        for (int d = 0; d < 3 - c; d++)
        {
            if (student[d].sum < student[d + 1].sum && student[d].cl == student[d + 1].cl)
            {
                k = student[d];
                student[d] = student[d + 1];
                student[d + 1] = k;
            }
        }
    }
}