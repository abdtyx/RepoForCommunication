#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

typedef struct _Student
{
    int Id;
    int cl;
    string name;
    double s1;
    double s2;
    double s3;
    double sum;
} Student;

// class Student
// {
// private:
//     int Id;
//     int cl;
//     string name;
//     double s1;
//     double s2;
//     double s3;
//     double sum;

// public:
//     Student(int a, int b, string c, double d, double e, double f, double g);
// };

// Student::Student(int a, int b, string c, double d, double e, double f, double g)
// {
//     Id = a;
//     cl = b;
//     name = c;
//     s1 = d;
//     s2 = e;
//     s3 = f;
//     sum = g;
// }

void paixu(Student student[], const int a);
void output(Student student[]);

int main()
{
    int a = 1, b = 2, c = 3;
    Student student[7] = {{10001, 11, "Zhang", 99.5, 88.5, 89.5, 277.5}, {10002, 12, "Yang", 77.9, 56.5, 87.5, 221.9}, {10003, 11, "Liang", 92.5, 99.0, 60.5, 252}, {10004, 11, "Cai", 93.6, 67.9, 90.5, 252}, {10005, 14, "Fu", 55.6, 67.9, 98.9, 222.4}, {10006, 12, "Mao", 22.1, 45.9, 99.2, 167.2}, {10007, 13, "Zhan", 35.6, 67.9, 88.0, 191.5}};
    // Student[0](10001, 11, "Zhang", 99.5, 88.5, 89.5, 0.0);
    // Student[1](10002, 12, "Yang", 77.9, 56.5, 87.5, 0.0);
    // Student[2](10003, 11, "Liang", 92.5, 99.0, 60.5, 0.0);
    // Student[3](10004, 11, "Cai", 93.6, 67.9, 90.5, 0.0);
    // Student[4](10005, 14, "Fu", 55.6, 67.9, 98.9, 0.0);
    // Student[5](10006, 12, "Mao", 22.1, 45.9, 99.2, 0.0);
    // Student[6](10007, 13, "Zhan", 35.6, 67.9, 88.0, 0.0);
    paixu(student, a);
    paixu(student, b);
    paixu(student, c);
    output(student);
    return 0;
}

void paixu(Student student[], const int a)
{
    if (a == 1)
    {
        Student s;
        for (int a = 0; a < 6; a++)
        {
            for (int b = 0; b < 6 - a; b++)
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
    if (a == 2)
    {
        Student k;
        for (int c = 0; c < 6; c++)
        {
            for (int d = 0; d < 6 - c; d++)
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
    if (a == 3)
    {
        Student k;
        for (int c = 0; c < 6; c++)
        {
            for (int d = 0; d < 6 - c; d++)
            {
                if (student[d].s1 < student[d + 1].s1 && student[d].cl == student[d + 1].cl && student[d].sum == student[d + 1].sum)
                {
                    k = student[d];
                    student[d] = student[d + 1];
                    student[d + 1] = k;
                }
            }
        }
    }
}

void output(Student student[])
{
    for (int i = 0; i < 7; i++)
    {
        cout << fixed << setprecision(1) << student[i].Id << " " << student[i].cl << " " << student[i].name << " " << student[i].s1 << " " << student[i].s2 << " " << student[i].s3<<" "<<student[i].sum << endl;
    }
}