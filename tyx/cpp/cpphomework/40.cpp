#include <bits/stdc++.h>

using namespace std;


class arr
{

public:
    int arr[105][105];
    int max;
void fill_outer_ring(int n, int record, int times) {
    if (n <= max / 2)
        return;
    arr[max - n][max - n] = 3 * (n - times) - 2 + record;
    // 往右
    int tmp = arr[max - n][max - n];
    for (int i = 1; i <= n - 2 - times; i++) {
        arr[max - n][max - n + i] = tmp + i;
    }
    // 往下****
    for (int i = 1; i <= n - 1 - times; i++) {
        arr[max - n + i][max - n] = tmp - i;
    }
    //最右边一列
    arr[max - n][n - 1] = 1 + record;
    tmp = arr[max - n][n - 1];
    for (int i = 1; i <= n - 2 - times; i++) {
        arr[max - n + i][n - 1] = tmp + i;
    }
    //最下面一行****
    tmp = arr[n - 1][max - n];
    for (int i = 1; i <= n - 1 - times; i++) {
        arr[n - 1][max - n + i] = tmp - i;
    }
    //向下递归
    // ot();
    // cout << endl;
    fill_outer_ring(n - 1, arr[max - n][n - 2], times + 1);
}
void ot() {
    for (int i = 0; i < max; i++) {
        for (int j = 0; j < max; j++) {
            if (j == 0)
                cout << arr[i][j];
            else
                cout << " " << arr[i][j];
        }
        cout << endl;
    }
    return;
}

};


void output(arr matrix) {
    for (int i = 0; i < matrix.max; i++) {
        for (int j = 0; j < matrix.max; j++) {
            if (j == 0)
                cout << matrix.arr[i][j];
            else
                cout << " " << matrix.arr[i][j];
        }
        cout << endl;
    }
    return;
}


int main() {
    arr matrix;
    int n;
    cin >> n;
    matrix.max = n;
    matrix.fill_outer_ring(n, 0, 0);
    output(matrix);
}