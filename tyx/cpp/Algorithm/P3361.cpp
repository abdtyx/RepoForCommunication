#include <bits/stdc++.h>

using namespace std;

typedef struct _Building {
    double xsum, ysum, num;
} Building;


int main() {
    Building b[25][25];
    memset(b, 0.0, sizeof(b));
    // double x_sum[25][25], y_sum[25][25], num[25][25];
    // memset(x_sum, 0.0, sizeof(x_sum));
    // memset(y_sum, 0.0, sizeof(y_sum));
    // memset(num, 0.0, sizeof(num));
    int n;
    cin >> n;
    long long int x, y, z;
    x = y = z = 0;
    int rxa, rxc, rya, ryc, rza, rzc;
    int rp = 2333333;
    cin >> rxa >> rxc >> rya >> ryc >> rza >> rzc;
    for (int i = 0; i < n; i++) {
        x = (y * rxa + rxc) % rp;
        y = (z * rya + ryc) % rp;
        z = (x * rza + rzc) % rp;
        double xx = (double)(x % 20) + (double)(y % 10) / 10.0 + (double)(z % 10) / 100.0;
        x = (y * rxa + rxc) % rp;
        y = (z * rya + ryc) % rp;
        z = (x * rza + rzc) % rp;
        double yy = (double)(x % 20) + (double)(y % 10) / 10.0 + (double)(z % 10) / 100.0;
        b[(int)xx][(int)yy].num++;
        b[(int)xx][(int)yy].xsum += xx;
        b[(int)xx][(int)yy].ysum += yy;
        // x_sum[(int)xx][(int)yy] += xx;
        // y_sum[(int)xx][(int)yy] += yy;
        // num[(int)xx][(int)yy]++;
        // cout << xx << ' ' << yy << endl;
    }
    double distance = 0;
    double sum = 0;
    for (int i = 1; i < 20; i++) {
        for (int j = 1; j < 20; j++) {
            // 枚举从0到i-1，0到j-1的building
            if (b[i][j].num == 0) continue;
            for (int k = 0; k < i; k++) {
                for (int l = 0; l < j; l++) {
                    if (b[k][l].num == 0) continue;
                    distance += (b[i][j].xsum + b[i][j].ysum) * b[k][l].num - (b[k][l].xsum + b[k][l].ysum) * b[i][j].num;
                    sum += b[i][j].num * b[k][l].num;
                    // distance += (x_sum[i][j] + y_sum[i][j]) * num[k][l] - (x_sum[k][l] + y_sum[k][l]) * num[i][j];
                    // sum += num[i][j] * num[k][l];
                }
            }
        }
    }
    cout << fixed << setprecision(5) << distance / sum;
    return 0;
}