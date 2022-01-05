#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000;
extent int n = 0;
double S1[100];
double S2[100];
double S3[100];
int s1_num = 5;
int s2_num = 3;
int s3_num = 0;

class Student
{
private:
    int num;
    string name;
    int Id;
    double s1;
    double s2;
    double s3;
    double sum;

public:
    Student(int _num = 0, string _name = "a", int _Id = 0, int _s1 = 0.0, int _s2 = 0.0, int _s3 = 0.0, double _sum = 0.0)
    {
        num = _num;
        name = _name;
        s1 = _s1;
        s2 = _s2;
        s3 = _s3;
        Id = _Id;
        sum = _sum;
    }
    ~Student();
    int getnum() { return num; }
    string getname() { return name; }
    int getId() { return Id; }
    // double gets1() { return s1; }
    // double gets2() { return s2; }
    // double gets3() { return s3; }
    double getsum() { return sum; }
    friend ifstream &operator>>(ifstream &ot, Student &stu);
    friend ostream &operator<<(ostream &out, const Student &student);
    friend ofstream &operator<<(ofstream &of, Student &stu);
};

ifstream &operator>>(ifstream &is, Student &stu)
{
    is >> stu.num >> stu.name >> stu.Id;
    for (int i = 0; i < s1_num; i++)
    {
        is >> S1[i];
    }
    is >> stu.s1;
    for (int i = 0; i < s2_num; i++)
    {
        is >> S2[i];
    }
    is >> stu.s2;
    for (int i = 0; i < s3_num; i++)
    {
        is >> S3[i];
    }
    is >> stu.s3;
    is >> stu.sum;
    return is;
}

ostream &operator<<(ostream &out, const Student &student)
{
    out << student.num << " " << student.name << " " << student.Id << " ";
    for (int i = 0; i < s1_num; i++)
    {
        out << S1[i] << " ";
    }
    out << student.s1 << " ";
    for (int i = 0; i < s2_num; i++)
    {
        out << S2[i] << " ";
    }
    out << student.s2 << " ";
    for (int i = 0; i < s3_num; i++)
    {
        out << S3[i] << " ";
    }
    out << student.s3 << " ";
    out << student.sum << endl;
    return out;
}

ofstream &operator<<(ofstream &of, Student &stu)
{

}

Student::~Student()
{
}

int main()
{
    Student stu[MAX];
    ifstream ifs("student.txt", std::ifstream::in);
    if (!ifs)
    {
        cout << "读入文件失败！" << endl;
        return -1;
    }
    while (ifs >> stu[n])
    {
        n++;
    }
    for (int i = 0; i < n; ++i)
    {
        cout << stu[i];
    }
    ifs.close();
    cout << "文件读入成功！" << endl;
    return 0;
}