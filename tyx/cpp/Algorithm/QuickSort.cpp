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

int Paritition1(int A[], int low, int high)
{
    int pivot = A[low];
    while (low < high)
    {
        Print(A);
        for (int i = 0; i < n; i++) {
            if (i == low) cout << "√";
            else if (i == high) cout << "Δ";
            else cout << "  ";
            cout << " ";
        }
        Sleep(1000);
        while (low < high && A[high] >= pivot)
        {
            --high;
            Print(A);
            for (int i = 0; i < n; i++) {
                if (i == low) cout << "√";
                else if (i == high) cout << "Δ";
                else cout << "  ";
                cout << " ";
            }
            Sleep(1000);
        }
        Print(A);
        for (int i = 0; i < n; i++) {
            if (i == low) cout << "√";
            else if (i == high) cout << "√";
            else cout << "  ";
            cout << " ";
        }
        Sleep(2000);
        // A[low] = A[high];
        swap(A[low], A[high]);
        Print(A);
        for (int i = 0; i < n; i++) {
            if (i == low) cout << ":D";
            else if (i == high) cout << ":D";
            else cout << "  ";
            cout << " ";
        }
        Sleep(2000);
        Print(A);
        for (int i = 0; i < n; i++) {
            if (i == low) cout << "Δ";
            else if (i == high) cout << "√";
            else cout << "  ";
            cout << " ";
        }
        Sleep(1000);
        while (low < high && A[low] <= pivot)
        {
            ++low;
            Print(A);
            for (int i = 0; i < n; i++) {
                if (i == low) cout << "Δ";
                else if (i == high) cout << "√";
                else cout << "  ";
                cout << " ";
            }
            Sleep(1000);
        }
        Print(A);
        for (int i = 0; i < n; i++) {
            if (i == low) cout << "√";
            else if (i == high) cout << "√";
            else cout << "  ";
            cout << " ";
        }
        Sleep(2000);
        // A[high] = A[low];
        swap(A[high], A[low]);
        Print(A);
        for (int i = 0; i < n; i++) {
            if (i == low) cout << ":D";
            else if (i == high) cout << ":D";
            else cout << "  ";
            cout << " ";
        }
        Sleep(2000);
    }
    // Print(A);
    // for (int i = 0; i < n; i++) {
    //     if (i == low) cout << "Δ";
    //     // else if (i == pivot) cout << "Δ";
    //     else cout << "  ";
    //     cout << " ";
    // }
    // Sleep(2000);
    // A[low] = pivot;
    // Print(A);
    // for (int i = 0; i < n; i++) {
    //     if (i == low) cout << "√";
    //     // else if (i == pivot) cout << "√";
    //     else cout << "  ";
    //     cout << " ";
    // }
    // Sleep(2000);
    return low;
}

void QuickSort(int A[], int low, int high) //快排母函数
{
    if (low < high)
    {
        int pivot = Paritition1(A, low, high);
        Print(A);
        for (int i = 0; i < 30; i++) cout << ' ';
        Sleep(3000);
        QuickSort(A, low, pivot - 1);
        QuickSort(A, pivot + 1, high);
    }
}

int main() {
    system("chcp 65001");
    system("cls");
    QuickSort(arr, 0, 9);
    // for (int i = 0; i < 10; i++) {
    //     cout << arr[i] << ' ';
    // }
    return 0;
}
