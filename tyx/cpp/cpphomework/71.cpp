#include <bits/stdc++.h>

using namespace std;

typedef struct _stu {
    string id;
    int cls;
    string name;
    double sc1, sc2, sc3, total;
} Stu;

bool mycmp(Stu a, Stu b) {
    if (a.cls == b.cls && a.total == b.total) return a.sc1 > a.sc2;
    else if (a.cls == b.cls) return a.total > b.total;
    else return a.cls < b.cls;
}

void opstu(Stu a) {
    char sp = ' ';
    cout << fixed << setprecision(1) << a.id << sp << a.cls << sp << a.name << sp << a.sc1 << sp << a.sc2 << sp << a.sc3 << sp << a.total << endl;
}

int main() {
    Stu student[7] = {{"10001", 11, "Zhang", 99.5, 88.5, 89.5, 99.5 + 88.5 + 89.5}, {"10002", 12, "Yang", 77.9, 56.5, 87.5, 77.9 + 56.5 + 87.5}, {"10003", 11, "Liang", 92.5, 99.0, 60.5, 92.5 + 99.0 + 60.5}, {"10004", 11, "Cai", 93.6, 67.9, 90.5, 93.6 + 67.9 + 90.5}, {"10005", 14, "Fu", 55.6, 67.9, 98.9, 55.6 + 67.9 + 98.9}, {"10006", 12, "Mao", 22.1, 45.9, 99.2, 22.1 + 45.9 + 99.2}, {"10007", 13, "Zhan", 35.6, 67.9, 88.0, 35.6 + 67.9 + 88.0}};
    sort(student, student + 7, mycmp);
    for (int i = 0; i < 7; i++) opstu(student[i]);
    return 0;
}