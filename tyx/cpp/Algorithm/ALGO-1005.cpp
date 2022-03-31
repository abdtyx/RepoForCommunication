#include <bits/stdc++.h>

using namespace std;

void Combine(int* combine);
void dfs(int* combine, vector<int> sequence, int sum);

int s, n;
bool ans = false;
int main() {
    cin >> n;
    cin >> s;
    int* combine = new int[n];
    Combine(combine);
    // for (int i = 0; i < n; i++) {
    //     cout << combine[i] << ' ';
    // }
    // cout << endl;
    vector<int> sequence;
    sequence.clear();
    int sum = 0;
    dfs(combine, sequence, sum);
    return 0;
}

void Combine(int* combine) {
    combine[0] = 1;
    int up = n - 1;
    int down = 1;
    for (int i = 1; i <= n; i++) {
        combine[i] = combine[i - 1] * up-- / down++;
    }
}

void dfs(int* combine, vector<int> sequence, int sum) {
    if (ans) return;
    if (sequence.size() == n) {
        if (sum != s) return;
        else {
            // output
            for (int k = 0; k < sequence.size(); k++) {
                int i = sequence[k];
                cout << i << ' ';
            }
            ans = true;
            return;
        }
    }
    for (int i = 1; i <= n; i++) {
        bool flag = false;
        for (int k = 0; k < sequence.size(); k++) {
            int j = sequence[k];
            if (j == i) {
                flag = true;
                break;
            }
        }
        if (flag) continue;
        else {
            // sequence.push_back(i);
            vector<int> tmp = sequence;
            tmp.push_back(i);
            dfs(combine, tmp, sum + i * combine[tmp.size() - 1]);
        }
    }
}