#include <bits/stdc++.h>
using namespace std;

typedef struct _student
{
    int id;
    int cl;
    string name;
    double s1;
    double s2;
    double s3;
    double sum;
} Student;

void info(Student student[]);
void search_1(Student student[], char a[], int i);
void search_2(Student student[], char a[], int i);
void search_3(Student student[], char a[], int i);
void search_4(Student student[], char a[]);
void search_5(Student student[], char a[], int i);

int main()
{
    Student student[7];
    int m;
    char a[100];
    scanf("%d %[^\n]", &m, a);
    info(student);
    for (int i; i < 7; i++)
    {
        student[i].sum = student[i].s1 + student[i].s2 + student[i].s3;
    }
    if (m == 1)
    {
        for (int i = 0; i < strlen(a); i++)
        {
            if (a[i] == '-' && i <= 2)
            {
                search_1(student, a, i);
            }
        }
    }
    else if (m == 2)
    {
        for (int i = 0; i < strlen(a); i++)
        {
            if (a[i] == '-' && i > 3)
            {
                search_2(student, a, i);
            }
        }
    }
    else if (m == 3)
    {
        for (int i = 0; i < strlen(a); i++)
        {
            if (a[i] == '*')
            {
                search_3(student, a, i);
            }
        }
    }
    else if (m == 4)
    {
        search_4(student, a);
    }
    else
    {
        for (int i = 0; i < strlen(a); i++)
        {
            if (a[i] == '.')
            {
                search_5(student, a, i);
            }
        }
    }
}

void info(Student student[])
{
    student[0].id = 10001;
    student[0].cl = 11;
    student[0].name = "Zhang";
    student[0].s1 = 99.5;
    student[0].s2 = 88.5;
    student[0].s3 = 89.5;
    student[1].id = 10003;
    student[1].cl = 11;
    student[1].name = "Liang";
    student[1].s1 = 92.5;
    student[1].s2 = 99.0;
    student[1].s3 = 60.5;
    student[2].id = 10004;
    student[2].cl = 11;
    student[2].name = "Cai";
    student[2].s1 = 89.6;
    student[2].s2 = 56.9;
    student[2].s3 = 90.5;
    student[3].id = 10002;
    student[3].cl = 12;
    student[3].name = "Yang";
    student[3].s1 = 77.9;
    student[3].s2 = 56.5;
    student[3].s3 = 87.5;
    student[4].id = 10006;
    student[4].cl = 12;
    student[4].name = "Mao";
    student[4].s1 = 22.1;
    student[4].s2 = 45.9;
    student[4].s3 = 99.2;
    student[5].id = 10007;
    student[5].cl = 13;
    student[5].name = "Zhan";
    student[5].s1 = 35.6;
    student[5].s2 = 67.9;
    student[5].s3 = 88.0;
    student[6].id = 10005;
    student[6].cl = 14;
    student[6].name = "Fu";
    student[6].s1 = 55.6;
    student[6].s2 = 67.9;
    student[6].s3 = 98.9;
}

void search_1(Student student[], char a[], int i)
{
    int num1, num2;
    char a1[100], a2[100];
    memcpy(a1, a, i);
    memcpy(a2, a + 3, strlen(a) - i - 1);
    num1 = atoi(a1);
    num2 = atoi(a2);
    for (int n = 0; n < 7; n++)
    {
        if (student[n].cl <= num2 && student[n].cl >= num1)
        {
            cout << fixed << setprecision(1) << student[n].id << " " << student[n].cl << " " << student[n].name << " " << student[n].s1 << " " << student[n].s2 << " " << student[n].s3 << endl;
        }
    }
}

void search_2(Student student[], char a[], int i)
{
    int num3, num4;
    char a1[100], a2[100];
    memcpy(a1, a, i);
    memcpy(a2, a + i + 1, strlen(a) - i - 1);
    num3 = atoi(a1);
    num4 = atoi(a2);
    for (int n = 0; n < 7; n++)
    {
        if (student[n].id <= num4 && student[n].id >= num3)
        {
            cout << fixed << setprecision(1) << student[n].id << " " << student[n].cl << " " << student[n].name << " " << student[n].s1 << " " << student[n].s2 << " " << student[n].s3 << endl;
        }
    }
}

void search_3(Student student[], char a[], int i)
{
    char b[100];
    for (int j = 0; j < i; j++)
    {
        b[j] = a[j];
    }
    for (int n = 0; n < 7; n++)
    {
        if (strstr(student[n].name.c_str(), b) != NULL)
        {
            cout << fixed << setprecision(1) << student[n].id << " " << student[n].cl << " " << student[n].name << " " << student[n].s1 << " " << student[n].s2 << " " << student[n].s3 << endl;
        }
    }
}

void search_4(Student student[], char a[])
{
    int num;
    num = atoi(a);
    for (int n = 0; n < 7; n++)
    {
        if (student[n].sum > num)
        {
            cout << fixed << setprecision(1) << student[n].id << " " << student[n].cl << " " << student[n].name << " " << student[n].s1 << " " << student[n].s2 << " " << student[n].s3 << endl;
        }
    }
}

void search_5(Student student[], char a[], int i)
{
    int num1, num2, num3, j;
    char a1[100], a2[100], a3[100];
    memcpy(a1, a, i);
    for (j = 0; j < strlen(a); j++)
    {
        if (a[j] == '-')
        {
            break;
        }
    }
    memcpy(a2, a + i + 1, j - i);
    memcpy(a3, a + j + 1, strlen(a) - j - 1);
    num1 = atoi(a1);
    num2 = atoi(a2);
    num3 = atoi(a3);
    for (int n = 0; n < 7; n++)
    {
        if (student[n].cl == num1)
        {
            if (student[n].id <= num3 && student[n].id >= num2)
            {
                cout << fixed << setprecision(1) << student[n].id << " " << student[n].cl << " " << student[n].name << " " << student[n].s1 << " " << student[n].s2 << " " << student[n].s3 << endl;
            }
        }
    }
}
