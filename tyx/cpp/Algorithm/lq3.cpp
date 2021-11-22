#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    string* hex = new string[n];
    for (int i = 0; i < n; i++) {
        cin >> hex[i];
    }
    string* bin = new string[n];
    for (int i = 0; i < n; i++) {
        // 十六进制转二进制
        // 检测有多少个三元组
        // 可以通过判断十六进制的位数来获得
        // 余1补2个0
        // 余2补1个9
        // 余0不补0
        int flag = hex[i].size() % 3;
        switch (flag) {
            case 0:
                // bin[i].push_back('0');
                break;
            case 1:
                bin[i].push_back('0');
                bin[i].push_back('0');
                break;
            case 2:
                bin[i].push_back('0');
                break;
            default:
                // do nothing
                cout << "nice day";
                // cout << "0" << endl;
                // return 0;
                // continue;
                break;
        }
        
    }
    return 0;
}