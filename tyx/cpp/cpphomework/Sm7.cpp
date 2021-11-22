#include <bits/stdc++.h>

using namespace std;

void jisuan(char * tmp1, char * tmp2, char *tmp3)
{
//insert code here
int len1 = strlen(tmp1);
int len2 = strlen(tmp2);
int len3 = max(len1, len2);
int deliver = 0;
for (int i = len3; i >= 0; i--) {
    if (len3 - i < len1 && len3 - i < len2) {
        int tmp = tmp1[len1 - len3 + i - 1] - '0' + tmp2[len2 - len3 + i - 1] - '0' + deliver;
        if (tmp >= 10) {
            deliver = 1;
            tmp -= 10;
            tmp3[i] = tmp + '0';
        }
        else {
            tmp3[i] = tmp + '0';
            deliver = 0;
        }
    }
    else if (len3 - i < len1) {
        int tmp = tmp1[len1 - len3 + i - 1] - '0' + deliver;
        if (tmp >= 10) {
            tmp -= 10;
            deliver = 1;
            tmp3[i] = tmp + '0';
        }
        else {
            tmp3[i] = tmp + '0';
            deliver = 0;
        }
    }
    else if (len3 - i < len2) {
        int tmp = tmp2[len2 - len3 + i - 1] - '0' + deliver;
        if (tmp >= 10) {
            tmp -= 10;
            deliver = 1;
            tmp3[i] = tmp + '0';
        }
        else {
            tmp3[i] = tmp + '0';
            deliver = 0;
        }
    }
    else {
        tmp3[i] = deliver + '0';
    }
}
if (tmp3[0] == '0') {
    for (int i = 0; i < len3; i++) {
        tmp3[i] = tmp3[i + 1];
    }
    tmp3[len3] = '\0';
}
}
int main(int argc, const char * argv[]) {
// insert code here...
char tmp1[200],tmp2[200],tmp3[300];
std::cin >> tmp1;
std::cin >> tmp2;
jisuan(tmp1,tmp2,tmp3);
std::cout << tmp3 <<std::endl;
return 0;
}