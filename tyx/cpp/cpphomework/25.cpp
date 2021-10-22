#include <bits/stdc++.h>

using namespace std;

typedef struct _Student {
    string username;
    int cls;
    double score;
} Student;


bool mycmp1(Student a, Student b) {
    return a.cls > b.cls;
}


bool mycmp2(Student a, Student b) {
    return a.score < b.score;
}


int main() {
    Student stu[3];
    int location1 = 0, location2 = 0;
    for (int i = 0; i < 3; i++) {
        double sc1, sc2, sc3;
        cin >> stu[i].username >> stu[i].cls >> sc1 >> sc2 >> sc3;
        stu[i].score = sc1 + sc2 + sc3;
    }
    sort(stu, stu + 3, mycmp1);
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
                cout << fixed << stu[i].cls << setprecision(1) << "," << stu[i].username << "," << stu[i].score;
            else 
                cout << fixed << setprecision(1) << ";" << stu[i].username << "," << stu[i].score;
        }
        cout << endl;
    }
    if (location2 != 0) {
        for (int i = location1; i < location2; i++) {
            if (i == location1)
                cout << fixed << stu[i].cls << setprecision(1) << "," << stu[i].username << "," << stu[i].score;
            else 
                cout << fixed << setprecision(1) << ";" << stu[i].username << "," << stu[i].score;
        }
        cout << endl;
    }
    if (location2 < 3 && location2 != 0) {
        for (int i = location2; i < 3; i++) {
            if (i == location2)
                cout << fixed << stu[i].cls << setprecision(1) << "," << stu[i].username << "," << stu[i].score;
            else 
                cout << fixed << setprecision(1) << ";" << stu[i].username << "," << stu[i].score;
        }
        cout << endl;
    }
}