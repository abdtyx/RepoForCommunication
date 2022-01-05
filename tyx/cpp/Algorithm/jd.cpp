#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    double* gpa = new double[n];
    double* score = new double[n];
    double* xuefen = new double[n];
    double sum_score = 0;
    for (int i = 0; i < n; i++) {
        cin >> score[i] >> xuefen[i];
        gpa[i] = 4.0 - 3.0 * (100.0 - score[i]) * (100.0 - score[i]) / 1600.0;
        sum_score += xuefen[i];
    }
    double _Gpa = 0;
    for (int i = 0; i < n; i++) {
        _Gpa += gpa[i] * xuefen[i] / sum_score;
    }
    cout << _Gpa;
}