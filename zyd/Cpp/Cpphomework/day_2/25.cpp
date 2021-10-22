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
} Student;

void bubble_cl(Student student[]);
void bubble_sum(Student student[]);

int main()
{
    Student student[3];
    Student n[3];
    for (int i = 0; i < 3; i++)
    {
        cin >> student[i].id >> student[i].cl >> student[i].s1 >> student[i].s2 >> student[i].s3;
        student[i].sum = student[i].s1 + student[i].s2 + student[i].s3;
    }
    bubble_cl(student);
    bubble_sum(student);
    cout << fixed << setprecision(1) << student[0].cl << "," << student[0].id << "," << student[0].sum;
    if (student[1].cl == student[0].cl)
    {
        cout << fixed << setprecision(1) << ";" << student[1].id << "," << student[1].sum;
    }
    else
    {
        cout << endl;
        cout << fixed << setprecision(1) << student[1].cl << "," << student[1].id << "," << student[1].sum;
    }
    if (student[1].cl == student[2].cl)
    {
        cout << fixed << setprecision(1) << ";" << student[2].id << "," << student[2].sum << endl;
    }
    else
    {
        cout << endl;
        cout << fixed << setprecision(1) << student[2].cl << "," << student[2].id << "," << student[2].sum;
    }
}

void bubble_cl(Student student[])
{
    Student s;
    for (int a = 0; a < 2; a++)
    {
        for (int b = 0; b < 2 - a; b++)
        {
            if (student[b].cl < student[b + 1].cl)
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
    for (int c = 0; c < 2; c++)
    {
        for (int d = 0; d < 2 - c; d++)
        {
            if (student[d].sum > student[d + 1].sum && student[d].cl == student[d + 1].cl)
            {
                k = student[d];
                student[d] = student[d + 1];
                student[d + 1] = k;
            }
        }
    }
}


