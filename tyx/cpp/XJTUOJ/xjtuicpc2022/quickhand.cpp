#include <bits/stdc++.h>

using namespace std;

int a[100005];

int Paritition(int A[], int low, int high) {
    int& b = A[low], & c = A[(low + high) / 2], & d = A[high];
    int e = b + c + d - max(max(b, c), d) - min(min(b, c), d);
    if (e == c) swap(b, c);
    if (e == d) swap(b, d);
    while (low < high) {
        if (low < high && A[low] == A[high]) --high;
        while (low < high && A[low] < A[high]) --high;
        swap(A[low], A[high]);
        if (low < high && A[low] == A[high]) ++low;
        while (low < high && A[low] < A[high]) ++low;
        swap(A[low], A[high]);
    }
    return low;
}

void Quick(int A[], int low, int high) {
    if (low < high) {
        int pivot = Paritition(A, low, high);
        Quick(A, low, pivot - 1);
        Quick(A, pivot + 1, high);
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    Quick(a, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    return 0;
}