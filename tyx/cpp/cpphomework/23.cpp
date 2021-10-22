#include <bits/stdc++.h>

using namespace std;

typedef struct _Student{
    string username;
    double score1;
    double score2;
    double score3;
    double total;
} Student;

int main() {
    queue<Student> q;
    Student tmp;
    for (int i = 0; i < 3; i++) {
        cin >> tmp.username >> tmp.score1 >> tmp.score2 >> tmp.score3;
        tmp.total = tmp.score1 + tmp.score2 + tmp.score3;
        q.push(tmp);
    }
    while(!q.empty()) {
        tmp = q.front();
        cout << fixed << setprecision(1) << tmp.username << "  " << tmp.score1 << "  " << tmp.score2 << "  " << tmp.score3 << "  " << tmp.total << endl;
        q.pop();
    }
}