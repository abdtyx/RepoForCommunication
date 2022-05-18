#include <iostream>

using namespace std;

void BubbleSort(int a[], int n);
void SelectionSort(int a[],int n);

int main(){
    int n = 10;
    int arr1[10], arr2[10];
    for (int i = 0; i < 10; i++) {
        cin >> arr1[i];
        arr2[i] = arr1[i];
    }
    BubbleSort(arr1, n);
    SelectionSort(arr2, n);
    for (int i = 0; i < n; i++) {
        if (i == 0) cout << arr1[i];
        else cout << ' ' << arr1[i];
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        if (i == 0) cout << arr2[i];
        else cout << ' ' << arr2[i];
    }
    return 0;
}

void SelectionSort(int a[],int n) {
    for (int i = 0; i < n; i++) {
        int _max = a[i];
        int pos = i;
        for (int j = i + 1; j < n; j++) {
            // _max = max(_max, a[j]);
            if (_max < a[j]) {
                _max = a[j];
                pos = j;
            }
        }
        // a[i] = _max;
        swap(a[i], a[pos]);
    }
}

void BubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool moo = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {swap(a[j], a[j + 1]); moo = true;}
        }
        if (!moo) break;
    }
}