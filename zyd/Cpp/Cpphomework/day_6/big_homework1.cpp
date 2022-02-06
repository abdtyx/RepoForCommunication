#include <bits/stdc++.h>
using namespace std;
const int MAX = 200;
int n = 0; // 用于计数Student类数量的参数

// class Start
// {
// public:
//     class Student;
//     Student operator=(const Student stu[]);
//     void start_p();
//     void begin();
// };

class Student
{
private:
    string Id;
    string cl;
    string name;
    double s1;
    double s2;
    double s3;
    double sum;

public:
    Student(string s3 = "a", string _cl = "c", string s4 = "a", double b = 0.0, double c = 0.0, double d = 0.0, double e = 0.0, double f = 0.0) : Id(s3), cl(_cl), name(s4), s1(b), s2(c), s3(d), sum(f){};
    friend void begin();
    friend void input();
    Student &operator=(const Student stu);
    void _delet();
    void select();
    void order();
    friend void _output(Student student);
    void setstudent(string a, string b, string c, double d, double e, double f, double g);
    void check1();
    void check2();
    friend ostream &operator<<(ostream &out, const Student &stu);
};

Student student[MAX];

void Student::setstudent(string a, string b, string c, double d, double e, double f, double g)
{
    Id = a;
    cl = b;
    name = c;
    s1 = d;
    s2 = e;
    s3 = f;
    sum = g;
}

ostream &operator<<(ostream &out, const Student &student)
{
    out << fixed << setprecision(1) << student.Id << "," << student.cl << "," << student.name << "," << student.s1 << "," << student.s2 << "," << student.s3 << "," << student.sum << endl;
    return out;
}

Student &Student::operator=(const Student stu)
{
    this->Id = stu.Id;
    this->cl = stu.cl;
    this->name = stu.name;
    this->s1 = stu.s1;
    this->s2 = stu.s2;
    this->s3 = stu.s3;
    this->sum = stu.sum;
    return *this;
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

void input()
{
    string _Id, _name, s, _cl;
    double _s1, _s2, _s3, _sum;
    while (1)
    {
        cout << "Id ";
        cin >> _Id;
        cout << "class ";
        cin >> _cl;
        cout << "name ";
        cin >> _name;
        cout << "score1 ";
        cin >> _s1;
        cout << "score2 ";
        cin >> _s2;
        cout << "score3 ";
        cin >> _s3;
        _sum = _s1 + _s2 + _s3;
        student[n].setstudent(_Id, _cl, _name, _s1, _s2, _s3, _sum);
        n++;
        cout << "continue?" << endl;
        cin >> s;
        if (s == "yes")
        {
            continue;
        }
        else if (s == "no")
        {
            break;
        }
        // else{
        //     cout<<
        // }
    }
    begin();
}

void Student::_delet()
{
    string s2, s;
    int i;
    student[MAX].check1();
    while (n != 0)
    {
        cin >> s2;
        for (i = 0; i < n; i++)
        {
            if (s2 == student[i].Id || s2 == student[i].name)
            {
                for (int j = i; j < n; j++)
                {
                    student[j] = student[j + 1];
                }
                n--;
                for (int i = 0; i < n; i++)
                {
                    cout << student[i];
                }
                break;
            }
        }
        if (i == n)
        {
            for (int i = 0; i < n; i++)
            {
                cout << student[i];
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

void Student::select()
{
    string s, s2;
    int count = 0;
    student[MAX].check2();
    while (n != 0)
    {
        cin >> s2;
        for (int i = 0; i < n; i++)
        {
            if (s2 == student[i].Id || s2 == student[i].cl)
            {
                cout << student[i];
                count++;
            }
        }
        if (count == 0)
        {
            cout << "there is no eligible student" << endl;
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

void Student::order()
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
    for (int c = 0; c < n - 1; c++)
    {
        for (int d = 0; d < n - c - 1; d++)
        {
            if (student[d].sum < student[d + 1].sum && student[d].cl == student[d + 1].cl)
            {
                s = student[d];
                student[d] = student[d + 1];
                student[d + 1] = s;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << student[i];
    }
    begin();
}

void _output(Student student)
{
    cout << student;
    begin();
}

void Student::check1()
{
    if (n == 1)
    {
        cout << "仅剩一名学生数据，无法执行操作" << endl;
    }
    if (n == 0)
    {
        cout << "没有学生数据！" << endl;
    }
}

void Student::check2()
{
    if (n == 0)
    {
        cout << "没有学生数据！" << endl;
    }
}

//  bool Student::operator==(string s)
//  {
//      return
//  }

int main()
{
    int p;
    begin();
    while (1)
    {
        if (p == 1)
        {
            input();
        }
        if (p == 2)
        {
            student[MAX]._delet();
        }
        if (p == 3)
        {
            student[MAX].select();
        }
        if (p == 4)
        {
            student[MAX].order();
        }
        if (p == 5)
        {
            for (int i = 0; i < n; i++)
            {
                cout << student[i];
            }
            begin();
        }
        if (p == 6)
        {
            break;
        }
        cin >> p;
    }
    // Student s1, s2;
    // s1.setstudent("1", "2", "4", 5, 6, 7, 8);
    // s2 = s1;
    // cout << s2;
    return 0;
}