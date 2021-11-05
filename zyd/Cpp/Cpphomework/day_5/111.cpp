#include <bits/stdc++.h>
using namespace std;

typedef struct _Student
{
    string cl;
    string Id;
    string name;
    double s1;
    double s2;
    double s3;
    double sum;
} Student;

Student student[100];
int n = 0;

void begin();
//void info(Student student[]);
void input(Student student[], int *n);
void _delete(Student student[], int *n);
void select(Student student[], int n);
void order(Student student[]);
void _output(Student student[], int n);

void bubble_cl(Student student[], int n);
void bubble_sum(Student student[], int n);
void output(Student student[], int n);

int main()
{
    //info(student);
    int p;
    begin();
    cin >> p;
    while (1)
    {
        if (p == 1)
        {
            input(student, &n);
        }
        if (p == 2)
        {
            _delete(student, &n);
        }
        if (p == 3)
        {
            select(student, n);
        }
        if (p == 4)
        {
            order(student);
        }
        if (p == 5)
        {
            _output(student, n);
        }
        if (p == 6)
        {
            break;
        }
        cin >> p;
    }
    return 0;
}

void begin()
{
    cout << "1.input" << endl;
    cout << "2.delete" << endl;
    cout << "3.select" << endl;
    cout << "4.order" << endl;
    cout << "5.output" << endl;
    cout << "6.quit" << endl;
    cout << "please input your option" << endl;
}

/*void info(Student student[])
{
    student[0].Id = "1001";
    student[0].cl = "11";
    student[0].name = "Zhang";
    student[0].s1 = 99.5;
    student[0].s2 = 88.5;
    student[0].s3 = 89.5;
    student[0].sum = 277.5;
    student[2].Id = "1002";
    student[2].cl = "12";
    student[2].name = "Yang";
    student[2].s1 = 77.9;
    student[2].s2 = 56.5;
    student[2].s3 = 87.5;
    student[2].sum = 221.5;
    student[1].Id = "1003";
    student[1].cl = "11";
    student[1].name = "Liang";
    student[1].s1 = 92.5;
    student[1].s2 = 99.0;
    student[1].s3 = 60.5;
    student[1].sum = 252.0;
}*/

void input(Student student[], int *n)
{
    string s;
    while (1)
    {
        cout << "Id ";
        cin >> student[*n].Id;
        cout << "class ";
        cin >> student[*n].cl;
        cout << "name ";
        cin >> student[*n].name;
        cout << "score1 ";
        cin >> student[*n].s1;
        cout << "score2 ";
        cin >> student[*n].s2;
        cout << "score3 ";
        cin >> student[*n].s3;
        student[*n].sum = student[*n].s1 + student[*n].s2 + student[*n].s3;
        cout << "continue?" << endl;
        cin >> s;
        n = &(++*n);
        if (s == "yes")
        {
            continue;
        }
        if (s == "no")
        {
            break;
        }
    }
    begin();
}

void _delete(Student student[], int *n)
{
    string s2, s;
    int i;
    while (1)
    {
        cin >> s2;
        for (i = 0; i < *n; i++)
        {
            if (s2 == student[i].Id || s2 == student[i].name)
            {
                for (int j = i; j < *n; j++)
                {
                    student[j] = student[j + 1];
                }
                n = &(--*n);
                output(student, *n);
                break;
            }
        }
        if (i == *n)
        {
            output(student, *n);
        }
        cout << "continue?" << endl;
        cin >> s;
        if (s == "yes")
        {
            continue;
        }
        if (s == "no")
        {
            break;
        }
    }
    begin();
}

void select(Student student[], int n)
{
    string s, s2;
    while (1)
    {
        cin >> s2;
        for (int i = 0; i < n; i++)
        {
            if (s2 == student[i].Id || s2 == student[i].cl)
            {
                cout << fixed << setprecision(1) << student[i].Id << "," << student[i].cl << "," << student[i].name << "," << student[i].s1 << "," << student[i].s2 << "," << student[i].s3 << "," << student[i].sum << endl;
            }
        }
        cout << "continue?" << endl;
        cin >> s;
        if (s == "yes")
        {
            continue;
        }
        if (s == "no")
        {
            break;
        }
    }
    begin();
}

void order(Student student[])
{
    bubble_cl(student, n);
    bubble_sum(student, n);
    output(student, n);
    begin();
}

void output(Student student[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << fixed << setprecision(1) << student[i].Id << "," << student[i].cl << "," << student[i].name << "," << student[i].s1 << "," << student[i].s2 << "," << student[i].s3 << "," << student[i].sum << endl;
    }
}

void bubble_cl(Student student[], int n)
{
    Student s;
    for (int a = 0; a < n - 1; a++)
    {
        for (int b = 0; b < n - a - 1; b++)
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

void bubble_sum(Student student[], int n)
{
    Student k;
    for (int c = 0; c < n - 1; c++)
    {
        for (int d = 0; d < n - c - 1; d++)
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

void _output(Student student[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << fixed << setprecision(1) << student[i].Id << "," << student[i].cl << "," << student[i].name << "," << student[i].s1 << "," << student[i].s2 << "," << student[i].s3 << "," << student[i].sum << endl;
    }
    begin();
}