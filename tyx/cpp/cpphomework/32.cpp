#include <bits/stdc++.h>

using namespace std;

class Matrix
{
    public:
        int arr1[3][3];
        int ans[3][3];
        int arr2[3][3];
    void mut();
    void ino();
    void inp();
    void out() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (j == 0)
                    cout << ans[i][j];
                else
                    cout << " " << ans[i][j];
            }
            cout << endl;
        }
    }
};

void Matrix::ino() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> arr1[i][j];
        }
    }
}



void Matrix::inp() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> arr2[i][j];
        }
    }
}


void Matrix::mut() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int tmp = 0;
            for (int k = 0; k < 3; k++) {
                tmp += arr1[i][k] * arr2[k][j];
            }
            ans[i][j] = tmp;
        }
    }
}



int main() {
    Matrix a;
    a.ino();
    a.inp();
    a.mut();
    a.out();
}