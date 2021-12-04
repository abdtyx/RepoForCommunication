#include <bits/stdc++.h>

using namespace std;

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

int Cls::number() {
    return this->Number;
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

void menu();
void input(vector<Cls>& cls);
void dlt(vector<Cls>& cls);
void select(vector<Cls>& cls);
void order(vector<Cls>& cls);
void output(vector<Cls>& cls);
int find_cls(vector<Cls>& cls, int number);
void quit();
inline bool cmp_student(Student a, Student b);
inline bool cmp_cls(Cls a, Cls b);

int main() {
    vector<Cls> cls;
    menu();
    int control;
    while (cin >> control) {
        switch (control) {
            case 1:
                input(cls);
                break;
            case 2:
                dlt(cls);
                break;
            case 3:
                select(cls);
                break;
            case 4:
                order(cls);
                break;
            case 5:
                output(cls);
                break;
            case 6:
                quit();
                break;
            default:
                cout << "Have a nice day!";
        }
    }
    return 0;
}

void menu() {
	cout << "1.input" << endl
		<< "2.delete" << endl
		<< "3.select" << endl
		<< "4.order" << endl
		<< "5.output" << endl
		<< "6.quit" << endl
		<< "please input your option" << endl;
	return;
}

void send_mail(Cls cls) {
    vector<Student> student = cls.get_stu();
    for (int i = 0; i < student.size(); i++) {
        vector<double> score = student[i].get_score();
        cout << fixed << setprecision(1) << student[i].id() << ',' << cls.number() << ',' << student[i].name() << ',' << score[0] << ',' << score[1] << ',' << score[2] << ',' << student[i].total() << endl;
    }
    return;
}

void send_mail(Student student, int number) {
    vector<double> score = student.get_score();
    cout << fixed << setprecision(1) << student.id() << ',' << number << ',' << student.name() << ',' << score[0] << ',' << score[1] << ',' << score[2] << ',' << student.total() << endl;
    return;
}

void input(vector<Cls>& cls) {
    string id, name;
    double score1, score2, score3;
    int number;
    cout << "Id ";
    cin >> id;
    cout << "class ";
    cin >> number;
    cout << "name ";
    cin >> name;
    cout << "score1 ";
    cin >> score1;
    cout << "score2 ";
    cin >> score2;
    cout << "score3 ";
    cin >> score3;
    Student student(id, name);
    student.score_push_back(score1);
    student.score_push_back(score2);
    student.score_push_back(score3);
    int cls_exist = find_cls(cls, number);
    if (cls_exist) {
        cls[cls_exist].stu_push_back(student);
    }
    else {
        Cls new_cls(number);
        new_cls.stu_push_back(student);
        cls.push_back(new_cls);
    }
    string to_where;
    cout << "continue?" << endl;
    cin >> to_where;
    if (to_where == "yes") 
        input(cls);
    else if (to_where == "no") 
        menu();
    return;
}

void dlt(vector<Cls>& cls) {
    string delete_what;
    cin >> delete_what;
    vector<Cls> new_cls;
    if (cls.size() > 1) {
        for (auto i : cls) {
            Cls c(i.number());
            vector<Student> stu = i.get_stu();
            for (auto j : stu) {
                if (delete_what != j.id() && delete_what != j.name()) {
                    send_mail(j, i.number());
                    c.stu_push_back(j);
                }
            }
            if (c.get_stu().size() != 0)
                new_cls.push_back(c);
        }
    }
    cls = new_cls;
    string to_where;
    cout << "continue?" << endl;
    cin >> to_where;
    if (to_where == "yes") 
        dlt(cls);
    else if (to_where == "no") 
        menu();
    return;
}

void select(vector<Cls>& cls) {
    string select_what;
    cin >> select_what;
    bool flag = true;
    int clas = atoi(select_what.c_str());
    for (auto i : cls) {
        if (i.number() == clas) {
            send_mail(i);
            flag = false;
            continue;
        }
        vector<Student> student = i.get_stu();
        for (auto j : student) {
            if (j.id() == select_what) {
                send_mail(j, i.number());
                flag = false;
            }
        }
    }
    if (flag)
        cout << "there is no eligible student" << endl;
    string to_where;
    cout << "continue?" << endl;
    cin >> to_where;
    if (to_where == "yes") 
        select(cls);
    else if (to_where == "no") 
        menu();
    return;
}

void order(vector<Cls>& cls) {
    vector<Cls> new_cls;
    sort(&cls[0], &cls[cls.size()], cmp_cls);
    for (int i = 0; i < cls.size(); i++) {
        int number = cls[i].number();
        vector<Student> student = cls[i].get_stu();
        sort(&student[0], &student[student.size()], cmp_student);
        Cls c(number);
        for (int j = 0; j < student.size(); j++) {
            c.stu_push_back(student[j]);
        }
        new_cls.push_back(c);
    }
    cls = new_cls;
    output(cls);
    return;
}

void output(vector<Cls>& cls) {
    for (auto i : cls) {
        send_mail(i);
    }
    menu();
    return;
}

int find_cls(vector<Cls>& cls, int number) {
    if (cls.size() == 0)
        return 0;
    for (int i = 0; i < cls.size(); i++) {
        if (cls[i].number() == number)
            return i;
    }
    return 0;
}

void quit() {
    exit(0);
    return;
}

inline bool cmp_student(Student a, Student b) {
    return a > b;
}

inline bool cmp_cls(Cls a, Cls b) {
    return a < b;
}