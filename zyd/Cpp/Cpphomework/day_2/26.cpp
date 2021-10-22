#include <bits/stdc++.h>
using namespace std;

typedef struct _student
{
    int id;
    int cl;
    double s1;
    double s2;
    double s3;
    double sum;
    int put = 0;
} Student;

void info(Student student[]);
void bubble_cl(Student student[]);
void bubble_sum(Student student[]);
void output(Student student[], int n);

int main()
{
    Student student[4];
    info(student);
    cin >> student[3].id >> student[3].cl >> student[3].s1 >> student[3].s2 >> student[3].s3;
    student[3].put = 1;
    for (int i = 0; i < 4; i++)
    {
        student[i].sum = student[i].s1 + student[i].s2 + student[i].s3;
    }
    if (student[3].id == student[0].id || student[3].id == student[1].id || student[3].id == student[2].id)
    {
        student[3].id = 10000;
    }
    bubble_cl(student);
    bubble_sum(student);
    for (int i = 0; i < 4; i++)
    {
        output(student, i);
    }
}

void info(Student student[])
{
    student[0].id = 10001;
    student[0].cl = 11;
    student[0].s1 = 99.5;
    student[0].s2 = 88.5;
    student[0].s3 = 89.5;
    student[2].id = 10002;
    student[2].cl = 12;
    student[2].s1 = 77.9;
    student[2].s2 = 56.5;
    student[2].s3 = 87.5;
    student[1].id = 10003;
    student[1].cl = 11;
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

void output(Student student[], int n)
{
    if (student[n].put==1)
        cout << fixed << setprecision(1) << student[n].id << " " << student[n].cl << " " << student[n].s1 << " " << student[n].s2 << " " << student[n].s3 <<" inserted"<< endl;
    else
        cout << fixed << setprecision(1) << student[n].id << " " << student[n].cl << " " << student[n].s1 << " " << student[n].s2 << " " << student[n].s3 << endl;
}