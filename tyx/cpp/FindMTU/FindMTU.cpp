// to_where的值就是目标地址
// 该程序可以找到从本地到目标地址的MTU
// 核心算法：二分查找
// 默认找202.117.0.20

// Error code
// 65500: 表示按MTU拆分的数据包被合并从而作出响应或者MTU大于65500，后者可能性极小。

#include <bits/stdc++.h>

using namespace std;

int main() {
    FILE* fp = NULL;
    char* cmd = new char[512];
    string pin = "ping -l ";
    string to_where = " 202.117.0.20";
    int left = 0, right = 65500;
    int ans = (left + right) / 2;
    string find_ans = pin + to_string(ans) + to_where;
    sprintf(cmd, find_ans.c_str());
    while (1) {
        if ((fp = popen(cmd, "r")) != NULL) {
            while (1) {
                if (fgets(cmd, 100, fp) != NULL) {
                    if (string(cmd) == "Request timed out.\n") {
                        // to lower
                        right = ans;
                        ans = (left + right) / 2;
                        if (ans == right - 1) {
                            printf("The MTU from here to target ip is: %d", ans);
                            return 0;
                        }
                        printf("Next: %d\n", ans);
                        find_ans = pin + to_string(ans) + to_where;
                        sprintf(cmd, find_ans.c_str());
                        break;
                    }
                    if (string(cmd) == "Ping statistics for" + to_where + ":\n") {
                        // to upper
                        left = ans;
                        ans = (left + right + 1) / 2;
                        if (ans == right) {
                            if (ans == 65500) {
                                printf("Cannot find the MTU from here to target ip. \nError: 65500.");
                                return 0;
                            }
                            printf("The MTU from here to target ip is: %d", ans);
                            return 0;
                        }
                        printf("Next: %d\n", ans);
                        find_ans = pin + to_string(ans) + to_where;
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