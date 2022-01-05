// to_where的值就是目标地址
// 该程序可以找到从本地到目标地址的MTU
// 核心算法：二分查找
// 默认找202.117.0.20

// Error code
// 65500: 表示按MTU拆分的数据包被合并从而作出响应或者MTU大于65500，后者可能性极小。

#include <bits/stdc++.h>
#include <regex>
#include <unistd.h>

using namespace std;

void hold() {
    while (1) {
        cout << "Successfully get!\n";
        sleep(10);
    }
}

int main() {
    FILE* fp = NULL;
    char* cmd = new char[512];
    system("chcp 437");
    regex r("^Reply from 202.117.0.20.*\n$");
    string pin = "ping -l ";
    string args = " -f ";
    string to_where = "202.117.0.20";
    int left = 0, right = 65500;
    int ans = (left + right) / 2;
    string find_ans = pin + to_string(ans) + args + to_where;
    sprintf(cmd, find_ans.c_str());
    while (1) {
        if ((fp = popen(cmd, "r")) != NULL) {
            while (1) {
                if (fgets(cmd, 100, fp) != NULL) {
                    if (string(cmd) == "Packet needs to be fragmented but DF set.\n") {
                        // to lower
                        right = ans;
                        ans = (left + right) / 2;
                        if (ans == right - 1) {
                            printf("The MTU from here to target ip is: %d\n", ans);
                            hold();
                            return 0;
                        }
                        printf("Next: %d\n", ans);
                        find_ans = pin + to_string(ans) + args + to_where;
                        sprintf(cmd, find_ans.c_str());
                        break;
                    }
                    if (/*string(cmd) == "Ping statistics for " + to_where + ":\n"*/regex_match(string(cmd), r)) {
                        // to upper
                        left = ans;
                        ans = (left + right + 1) / 2;
                        if (ans == right) {
                            if (ans == 65500) {
                                printf("Cannot find the MTU from here to target ip. \nError: 65500.\n");
                                hold();
                                return 0;
                            }
                            printf("The MTU from here to target ip is: %d\n", ans);
                            hold();
                            return 0;
                        }
                        printf("Next: %d\n", ans);
                        find_ans = pin + to_string(ans) + args + to_where;
                        sprintf(cmd, find_ans.c_str());
                        break;
                    }
                }
                else
                    break;
            }
        }
        else 
            break;
    }
    return 0;
}