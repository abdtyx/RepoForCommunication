#include <bits/stdc++.h>

using namespace std;

inline bool cmp_student(Student a, Student b) {
    return a > b;
}

inline bool cmp_cls(Cls a, Cls b) {
    return a < b;
}

class Student {
    private:
        string Id;
        string Name;
        vector<double> Score;
        double Total;
        double total_now();
    public:
        Student(string _Id, string _Name);
        ~Student();
        double total();
        string id();
        string name();
        double score_push_back(double _Score);
        void score_pop_back();
        vector<double> get_score();
        friend bool operator>(Student& a, Student& b);
        friend bool operator<(Student& a, Student& b);
        friend bool operator==(Student& a, Student& b);
};

class Cls {
    private:
        int Number;
        vector<Student> Stu;
    public:
        Cls(int _Number);
        ~Cls();
        int number();
        void stu_push_back(Student _Stu);
        void stu_pop_back();
        vector<Student> get_stu();
        friend bool operator<(Cls& a, Cls& b);
        friend bool operator>(Cls& a, Cls& b);
        friend bool operator==(Cls& a, Cls& b);
};

Student::Student(string _Id, string _Name) {
    Id = _Id;
    Name = _Name;
}

Student::~Student() {
    Id.clear();
    Name.clear();
    Score.clear();
    Total = 0;
}

double Student::total() {
    return this->Total;
}

string Student::id() {
    return this->Id;
}

string Student::name() {
    return this->Name;
}

double Student::score_push_back(double _Score) {
    this->Score.push_back(_Score);
    return total_now();
}

void Student::score_pop_back() {
    this->Score.pop_back();
}

double Student::total_now() {
    double sum = 0;
    for (int i = 0; i < this->Score.size(); i++) {
        sum += Score[i];
    }
    this->Total = sum;
    return sum;
}

vector<double> Student::get_score() {
    return this->Score;
}

bool operator<(Student& a, Student& b) {
    return a.total() < b.total();
}

bool operator>(Student& a, Student& b) {
    return a.total() > b.total();
}

bool operator==(Student& a, Student& b) {
    return a.total() == b.total();
}

Cls::Cls(int _Number) {
    this->Number = _Number;
}

Cls::~Cls() {
    this->Number = 0;
    this->Stu.clear();
}

void Cls::stu_push_back(Student _Stu) {
    this->Stu.push_back(_Stu);
}

void Cls::stu_pop_back() {
    this->Stu.pop_back();
}

vector<Student> Cls::get_stu() {
    return this->Stu;
}

bool operator<(Cls& a, Cls& b) {
    return a.number() < b.number();
}

bool operator>(Cls& a, Cls& b) {
    return a.number() > b.number();
}

bool operator==(Cls& a, Cls& b) {
    return a.number() == b.number();
}

int main() {
    vector<Cls> cls;
}