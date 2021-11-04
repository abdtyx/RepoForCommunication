#include <bits/stdc++.h>
#include <regex>

using namespace std;

int main() {
    // 二进制枚举N个人说假话的情况，然后对于所有证词跑一遍，说真话就直接按真话来，说假话就反着来
    // 显然可能出现证词互相冲突的情况，不妨用bool数组存人，对证词检验时根据数组中bool值的情况判断是否冲突，若冲突，回溯。
    int m, n, p;
    cin >> m >> n >> p;
    pair<string, bool> person[25];  // pair<name, guilty>
    // int person_length = 0;
    pair<string, string> sentence[105];  // pair<name, evidence>
    regex r("(.*): (.*)");
    smatch _m;
    for (int i = 0; i < p; i++) {
        string reg;
        cin >> reg;
        regex_search(reg, _m, r);
        sentence[i].first = _m.str(1);
        sentence[i].second = _m.str(2);
    }
    for (int i = 0; i < m; i++) {
        string tmp;
        cin >> tmp;
        person[i + 1].first = tmp;
        person[i + 1].second = false;
    }
    for (int tot = 0, mask = (1 << m); tot < mask; tot++) {
        int select = 0; // select用来记录取了几个人，只对取了n个人的情况进行计算
        // 冲突回溯flag
        bool flag = true;   // 必须遍历完所有情况时这个解满足题目条件，flag才会为true
        // 真值表
        bool truth[25];
        pair<int, int> is_guilty[25];   // pari<guilty, not_guilty> 
        // initialize
        for (int z = 0; z < 25; z++) {
            truth[z] = false;
            is_guilty[z].first = 0;
            is_guilty[z].second = 0;
            person[z].second = false;
        }
        for (int i = 0; i < m; i++) {
            if ((tot << i) & 1) {
                select++;
                truth[i + 1] = false;
            }
        }
        if (select != n)
            continue;
        else {
            // 对语句进行判定。
            for (int j = 0; j < p; j++) {
                // I am guilty.
                if (sentence[j].second == "I am guilty.") {
                    // find person number
                    string tmp = sentence[j].first;
                    int person_number = 1;
                    for (; person_number < 25; person_number++) {
                        if (person[person_number].first == tmp) {
                            break;
                        }
                    }
                    if (truth[person_number]) {
                        // 判定冲突回溯
                        if (is_guilty[person_number].second != 0) {
                            // 已经是not_guilty，但是又guilty
                            flag = false;
                            break;
                        }
                        else {
                            is_guilty[person_number].first++;
                        }
                    }
                    else {
                        // 他说的是假话，所以得反着来，那他就not guilty
                        // 判定冲突回溯
                        if (is_guilty[person_number].first != 0) {
                            flag = false;
                            break;
                        }
                        else
                            is_guilty[person_number].second++;
                    }
                }
                // I am not guilty.
                if (sentence[j].second == "I am not guilty.") {
                    // find person number
                    string tmp = sentence[j].first;
                    int person_number = 1;
                    for (; person_number < 25; person_number++) {
                        if (person[person_number].first == tmp)
                            break;
                    }
                    if (truth[person_number]) {
                        if (is_guilty[person_number].first != 0) {
                            flag = false;
                            break;
                        }
                        else
                            is_guilty[person_number].second++;
                    }
                    else {
                        if (is_guilty[person_number].second != 0) {
                            flag = false;
                            break;
                        }
                        else
                            is_guilty[person_number].first++;
                    }
                }
                // XXX is guilty
                // find person number
                string temp = 
                // XXX is not guilty.
            }
        }
    }
}