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
    string* oct = new string[n];
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
        // 转换
        for (int j = 0; j < hex[i].size(); j++) {
            int dec;
            if (hex[i][j] >= '0' && hex[i][j] <= '9') {
                dec = hex[i][j] - '0';
            }
            else if (hex[i][j] >= 'A' && hex[i][j] <= 'F') {
                dec = hex[i][j] - 'A' + 10;
            }
            for (int k = 3; k >= 0; k--) {
                int tmp = dec;
                int to_push = ((tmp >> k) & 1) + '0';
                bin[i].push_back(to_push);
            }
        }
        // bin to oct
        for (int j = 0; j < bin[i].size(); j++) {
            if (j % 3 == 0) {
                int to_push = 4 * (bin[i][j] - '0') + 2 * (bin[i][j + 1] - '0') + 1 * (bin[i][j + 2] - '0');
                if (j != 0 || to_push != 0)
                    oct[i].push_back(to_push + '0');
            }
        }
    }
    // output
    for (int i = 0; i < n; i++) {
        cout << oct[i] << endl;
    }
    return 0;
}