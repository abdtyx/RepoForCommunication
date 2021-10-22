#include <bits/stdc++.h>

using namespace std;

typedef struct _Student {
    string username;
    int cls;
    string name;
    double sc1, sc2, sc3;
    string md;
} Student;


double Total(Student a) {
    return a.sc1 + a.sc2 + a.sc3;
}

bool mycmp(Student a, Student b) {
    return a.cls < b.cls;
}


bool mycmp2(Student a, Student b) {
    return Total(a) > Total(b);
}



int main() {
    Student stu[3] = {{"10001", 11, "Zhang", 99.5, 88.5, 89.5}, {"10003", 11, "Liang", 92.5, 99.0, 60.5}, {"10002", 12, "Yang", 77.9, 56.5, 87.5}};
    Student mod;
    int location1 = 0, location2 = 0;
    // int flag = -1;
    cin >> mod.username >> mod.cls >> mod.name >> mod.sc1 >> mod.sc2 >> mod.sc3;
    for (int i = 0; i < 3; i++) {
        if (stu[i].username == mod.username) {
            stu[i] = mod;
            stu[i].md = " modified";
        }
    }
    sort(stu, stu + 3, mycmp);
    for (int i = 0; i < 2; i++) {
        if (stu[0].cls == stu[i + 1].cls)
            location1 = i + 2;
        else {
            location1 = i + 1;
            break;
        }
    }
    for (int i = location1; i < 2; i++) {
        if (stu[location1].cls == stu[i + 1].cls)
            location2 = i + 2;
        else {
            location2 = i + 1;
            break;
        }
    }
    if (location1 == 2 && location2 == 0)
        location2 = 3;
    sort(stu, stu + location1, mycmp2);
    if (location2 > location1 + 1)
        sort(stu + location1, stu + location2, mycmp2);
    if (location2 < 3 && location2 != 0)
        sort(stu + location2, stu + 3, mycmp2);
    if (location1 != 0) {
        for (int i = 0; i < location1; i++) {
            if (i == 0)
                cout << fixed << stu[i].cls << setprecision(1) << " " << stu[i].username << " " << stu[i].name << " " << stu[i].sc1 << " " << stu[i].sc2 << " " << stu[i].sc3;
            else 
                cout << fixed << setprecision(1) << "\n   " << stu[i].username << " " << stu[i].name << " " << stu[i].sc1 << " " << stu[i].sc2 << " " << stu[i].sc3;
            if (stu[i].md == " modified")
                cout << stu[i].md;
        }
        cout << endl;
    }
    if (location2 != 0) {
        for (int i = location1; i < location2; i++) {
            if (i == location1)
                cout << fixed << stu[i].cls << setprecision(1) << " " << stu[i].username << " " << stu[i].name << " " << stu[i].sc1 << " " << stu[i].sc2 << " " << stu[i].sc3;
            else 
                cout << fixed << setprecision(1) << "\n   " << stu[i].username << " " << stu[i].name << " " << stu[i].sc1 << " " << stu[i].sc2 << " " << stu[i].sc3;
            if (stu[i].md == " modified")
                cout << stu[i].md;
        }
        cout << endl;
    }
    if (location2 < 3 && location2 != 0) {
        for (int i = location2; i < 3; i++) {
            if (i == location2)
                cout << fixed << stu[i].cls << setprecision(1) << " " << stu[i].username << " " << stu[i].name << " " << stu[i].sc1 << " " << stu[i].sc2 << " " << stu[i].sc3;
            else 
                cout << fixed << setprecision(1) << "\n   " << stu[i].username << " " << stu[i].name << " " << stu[i].sc1 << " " << stu[i].sc2 << " " << stu[i].sc3;
            if (stu[i].md == " modified")
                cout << stu[i].md;
        }
        cout << endl;
    }

}

