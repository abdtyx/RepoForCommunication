#include <bits/stdc++.h>

using namespace std;

int a[1000005];

int Paritition(int A[], int low, int high)
{
    // optimize1
    int& b = A[low], & c = A[(low + high) / 2], & d = A[high];
    int e = b + c + d - max(b, max(c, d)) - min(b, min(c, d));
    if (c == e) swap(c, b);
    if (d == e) swap(d, b);
    // optimize1
    int pivot = A[low];
    while (low < high) {
        while (low < high && A[high] >= A[low]) --high;
        // if (low == high) break;
        swap(A[low], A[high]);
        while (low < high && A[low] <= A[high]) ++low;
        // if (low == high) break;
        swap(A[high], A[low]);
    }
    return low;
}

void QuickSort(int A[], int low, int high)
{
    if (low < high) {
        int pivot = Paritition(A, low, high);
        QuickSort(A, low, pivot - 1);
        QuickSort(A, pivot + 1, high);
    }
}

int main() {
    // double start = clock();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    QuickSort(a, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    // double finish = clock();
    // cout << endl << (finish - start) / CLOCKS_PER_SEC;
    return 0;
}
