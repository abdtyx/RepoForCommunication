#include <bits/stdc++.h>
#include <regex>

using namespace std;

int main() {
    // 二进制枚举N个人说假话的情况，然后对于所有证词跑一遍，说真话就直接按真话来，说假话就反着来
    // 显然可能出现证词互相冲突的情况，不妨用bool数组存人，对证词检验时根据数组中bool值的情况判断是否冲突，若冲突，回溯。
    int m, n, p;
    cin >> m >> n >> p;
    // string st;
    // getline(cin, st);
    pair<string, bool> person[25];  // pair<name, guilty>
    // int person_length = 0;
    pair<string, string> sentence[105];  // pair<name, evidence>
    // vector<string> ans;
    set<string> ans;
    ans.clear();
    regex r("(.*): (.*)");
    smatch _m;
    for (int i = 0; i < m; i++) {
        string tmp;
        cin >> tmp;
        // getline(cin, tmp);
        person[i + 1].first = tmp;
        person[i + 1].second = false;
    }
    // char abandon;
    string stt;
    // cin >> abandon;
    getline(cin, stt);
    for (int i = 0; i < p; i++) {
        string reg;
        // cin >> reg;
        getline(cin, reg);
        regex_search(reg, _m, r);
        sentence[i].first = _m.str(1);
        sentence[i].second = _m.str(2);
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
            truth[z] = true;
            is_guilty[z].first = 0;
            is_guilty[z].second = 0;
            person[z].second = false;
        }
        for (int i = 0; i < m; i++) {
            if ((1 << i) & tot) {
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
                else if (sentence[j].second == "I am not guilty.") {
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
                // find person number
                else {
                    bool go_to_1 = false, go_to_2 = false;
                    int person_number = 1;
                    for (; person_number < 25; person_number++) {
                        if (person[person_number].first + " is guilty." == sentence[j].second) {
                            go_to_1 = true;
                            break;
                        }
                        else if (person[person_number].first + " is not guilty." == sentence[j].second) {
                            go_to_2 = true;
                            break;
                        }
                    }
                    if (go_to_1) {
                        // XXX is guilty
                        // find sentence_number
                        string tmp = sentence[j].first;
                        int sentence_number = 1;
                        for (; sentence_number < 25; sentence_number++) {
                            if (person[sentence_number].first == tmp)
                                break;
                        }
                        if (truth[sentence_number]) {
                            if (is_guilty[person_number].second != 0) {
                                flag = false;
                                break;
                            }
                            else
                                is_guilty[person_number].first++;
                        }
                        else {
                            if (is_guilty[person_number].first != 0) {
                                flag = false;
                                break;
                            }
                            else
                                is_guilty[person_number].second++;
                        }
                    }
                    else if (go_to_2) {
                        // XXX is not guilty
                        // find sentence_number
                        string tmp = sentence[j].first;
                        int sentence_number = 1;
                        for (; sentence_number < 25; sentence_number++) {
                            if (person[sentence_number].first == tmp)
                                break;
                        }
                        if (truth[sentence_number]) {
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
                }
            }
            // 语句判定完了，现在看该解是否成立
            if (flag) {
                // 不起冲突
                vector<string> possible;
                possible.clear();
                for (int k = 1; k <= m; k++) {
                    if (is_guilty[k].first)
                        possible.push_back(person[k].first);
                }
                if (possible.size() == 1) {
                    // ans.insert(possible[0]);
                    if (ans.find(possible[0]) == ans.end()) {
                        ans.insert(possible[0]);
                    }
                }
            }
        }
    }
    if (ans.size() > 1)
        cout << "Cannot Determine";
    else if (ans.size() == 0)
        cout << "Impossible";
    else
        cout << *ans.begin();
    return 0;
}