#include <iostream>
#include <algorithm>

using namespace std;

typedef struct _stu {
    int stuno;
    string name;
    double score;
    friend bool operator<(struct _stu& a, struct _stu& b) {
        return a.score > b.score;
    }
} Stu;

int main() {
    Stu stu[100];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> stu[i].stuno >> stu[i].name >> stu[i].score;
    }
    sort(stu, stu + n);
    for (int i = 0; i < n; i++) {
        cout << stu[i].stuno << ' ' << stu[i].name << ' ' << stu[i].score << endl;
    }
    return 0;
}