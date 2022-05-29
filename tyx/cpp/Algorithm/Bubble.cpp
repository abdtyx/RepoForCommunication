#include <bits/stdc++.h>
#include <windows.h>

using namespace std;

int n = 10;
int arr[10] = {6, 1, 2, 7, 9, 3, 4, 5, 10, 8};

void Print(int a[]) {
    system("cls");
    for (int i = 10; i >= 1 /*max*/; i--) {
        for (int j = 0; j < n; j++) {
            if (a[j] >= i) {cout << "**";}
            else cout << "  ";
            cout << " ";
        }
        cout << endl;
    }
}


void BubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool moo = false;
        Print(a);
        for (int k = 0; k < 30; k++) cout << ' ';
        Sleep(1000);
        for (int j = 0; j < n - i - 1; j++) {
            Print(a);
            for (int k = 0; k < n; k++) {
                if (k == j) cout << "Δ";
                else if (k == j + 1) cout << "Δ";
                else cout << "  ";
                cout << " ";
            }
            Sleep(1000);
            if (a[j] > a[j + 1]) {
                Print(a);
                for (int k = 0; k < n; k++) {
                    if (k == j) cout << "×";
                    else if (k == j + 1) cout << "×";
                    else cout << "  ";
                    cout << " ";
                }
                Sleep(1000);
                swap(a[j], a[j + 1]);
                Print(a);
                for (int k = 0; k < n; k++) {
                    if (k == j) cout << "√";
                    else if (k == j + 1) cout << "√";
                    else cout << "  ";
                    cout << " ";
                }
                Sleep(1000);
                moo = true;
            }
        }
        if (!moo) {
            Print(a);
            for (int k = 0; k < n; k++) {
                cout << "√ ";
            }
            Sleep(1000);
            break;
        }
    }
}



int main() {
    system("chcp 65001");
    system("cls");
    system("pause");
    BubbleSort(arr, 10);
    while (1) {
        Sleep(1000);
    }
    return 0;
}