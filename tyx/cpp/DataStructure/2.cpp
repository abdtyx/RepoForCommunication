#include <iostream>
#include <string.h>

using namespace std;

int main() {
    char arr1[1005], arr2[1005], ans[1005];
    memset(arr1, 0, 1005);
    memset(arr2, 0, 1005);
    memset(ans, 0, 1005);
    cin >> arr1 >> arr2;
    int ctr1 = strlen(arr1), ctr2 = strlen(arr2), carry = 0;
    if (ctr1 > ctr2) {
        while (ctr1) {
            if (ctr2 > 0) {
                int tmp = arr1[--ctr1] - '0' + arr2[--ctr2] - '0' + carry;
                carry = 0;
                if (tmp >= 10) {
                    tmp -= 10;
                    carry = 1;
                }
                ans[ctr1 + 1] = tmp + '0';
            }
            else {
                int tmp = arr1[--ctr1] - '0' + carry;
                carry = 0;
                if (tmp >= 10) {
                    tmp -= 10;
                    carry = 1;
                }
                ans[ctr1 + 1] = tmp + '0';
            }
        }
    }
    else {
        while (ctr2) {
            if (ctr1 > 0) {
                int tmp = arr1[--ctr1] - '0' + arr2[--ctr2] - '0' + carry;
                carry = 0;
                if (tmp >= 10) {
                    tmp -= 10;
                    carry = 1;
                }
                ans[ctr2 + 1] = tmp + '0';
            }
            else {
                int tmp = arr2[--ctr2] - '0' + carry;
                carry = 0;
                if (tmp >= 10) {
                    tmp -= 10;
                    carry = 1;
                }
                ans[ctr2 + 1] = tmp + '0';
            }
        }
    }
    if (carry) cout << carry << ans + 1;
    else cout << ans + 1;
    return 0;
}