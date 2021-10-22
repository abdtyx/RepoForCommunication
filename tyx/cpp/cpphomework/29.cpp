#include <bits/stdc++.h>
#include <regex>



using namespace std;


void query1(string reg);
void query2(string reg);
void query3(string reg);
void query4(double sc);
void query5(string reg);


typedef struct _Student {
    string username;
    int cls;
    string name;
    double sc1, sc2, sc3, total;
} Student;

double Total(Student a) {
    return a.sc1 + a.sc2 + a.sc3;
}

Student stu[7] = {{"10001", 11, "Zhang", 99.5, 88.5, 89.5}, {"10003", 11, "Liang", 92.5, 99.0, 60.5}, {"10004", 11, "Cai", 89.6, 56.9, 90.5}, {"10002", 12, "Yang", 77.9, 56.5, 87.5}, {"10006", 12, "Mao", 22.1, 45.9, 99.2}, {"10007", 13, "Zhan", 35.6, 67.9, 88.0}, {"10005", 14, "Fu", 55.6, 67.9, 98.9}};

void sendMail(Student a) {
    cout << fixed << setprecision(1) << a.username << " " << a.cls << " " << a.name << " " << a.sc1 << " " << a.sc2 << " " << a.sc3 << endl;
}




int main() {
    for (int i = 0; i < 7; i++) {
        stu[i].total = Total(stu[i]);
    }
    int flag;
    cin >> flag;
    string trans;
    switch (flag) {
        case 1:
            // string trans1;
            cin >> trans;
            query1(trans);
            break;
        case 2:
            // string trans2;
            cin >> trans;
            query2(trans);
            break;
        case 3:
            // string trans3;
            cin >> trans;
            query3(trans);
            break;
        case 4:
            double sc;
            cin >> sc;
            query4(sc);
            break;
        case 5:
            // string trans4;
            cin >> trans;
            query5(trans);
            break;
    }
}

void query1(string reg) {
    regex r("^(\\d+)-(\\d+)$");
    smatch m;
    regex_match(reg, m, r);
    string fr = m.str(1);
    string rr = m.str(2);
    int front = atoi(fr.c_str());
    int rear = atoi(rr.c_str());
    for (int i = 0; i < 7; i++) {
        if (stu[i].cls >= front && stu[i].cls <= rear)
            sendMail(stu[i]);
    }
}



void query2(string reg) {
    regex r("^(\\d+)-(\\d+)$");
    smatch m;
    regex_match(reg, m, r);
    string fr = m.str(1);
    string rr = m.str(2);
    int front = atoi(fr.c_str());
    int rear = atoi(rr.c_str());
    for (int i = 0; i < 7; i++) {
        if (atoi(stu[i].username.c_str()) >= front && atoi(stu[i].username.c_str()) <= rear)
            sendMail(stu[i]);
    }
}



void query3(string reg) {
    reg.pop_back();
    string mag = "^(" + reg + ").*$";
    regex r(mag);
    // smatch m;
    for (int i = 0; i < 7; i++) {
        if (regex_match(stu[i].name, r))
            sendMail(stu[i]);
    }
}



void query4(double sc) {
    for (int i = 0; i < 7; i++) {
        if (stu[i].total >= sc)
            sendMail(stu[i]);
    }
}



void query5(string reg) {
    regex r("^(\\d+)\.(\\d+)-(\\d+)$");
    smatch m;
    regex_match(reg, m, r);
    int cas = atoi(m.str(1).c_str());
    int front = atoi(m.str(2).c_str());
    int rear = atoi(m.str(3).c_str());
    for (int i = 0; i < 7; i++) {
        if (stu[i].cls == cas && atoi(stu[i].username.c_str()) >= front && atoi(stu[i].username.c_str()) <= rear)
        sendMail(stu[i]);
    }
}