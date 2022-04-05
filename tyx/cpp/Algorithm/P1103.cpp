#include <bits/stdc++.h>
#pragma GCC optimize(3, "Ofast", "inline")

using namespace std;
typedef struct _book {
    int height, wide, weight;
    // bool exist;
    bool operator<(struct _book b) {
        return height < b.height;
    }
} Book;

int main() {
    Book book[1000];
    for (int i = 0; i < 1000; i++) {
        book[i].height = book[i].weight = book[i].wide = 0;
        // book[i].exist = true;
    }
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> book[i].height >> book[i].wide;
    }
    sort(book, book + n);
    for (int i = 0; i < n; i++) {
        if (i == 0) book[i].weight = (int)abs(book[0].wide - book[1].wide);
        else if (i == n - 1) book[i].weight = (int)abs(book[i].wide - book[i - 1].wide);
        else book[i].weight = (int)abs(book[i].wide - book[i - 1].wide) + (int)abs(book[i].wide - book[i + 1].wide) - (int)abs(book[i - 1].wide - book[i + 1].wide);
    }
    // delete k nodes
    for (int i = 0; i < k; i++) {
        int where_max = -1, max_weight = -285714285;
        for (int j = 0; j < n; j++) {
            if (book[j].weight > max_weight) {
                where_max = j;
                max_weight = book[j].weight;
            }
        }
        // delete j node
        for (int j = where_max; j < n - 1; j++) {
            book[j] = book[j + 1];
        }
        n--;
        if (where_max == 0) book[where_max].weight = (int)abs(book[where_max].wide - book[where_max + 1].wide);
        else if (where_max == n) book[where_max - 1].weight = (int)abs(book[where_max - 1].wide - book[where_max - 2].wide);
        else {
            if (where_max == n - 1) book[where_max].weight = (int)abs(book[where_max].wide - book[where_max - 1].wide);
            else book[where_max].weight = (int)abs(book[where_max].wide - book[where_max - 1].wide) + (int)abs(book[where_max].wide - book[where_max + 1].wide) - (int)abs(book[where_max - 1].wide - book[where_max + 1].wide);
            if (where_max == 1) book[where_max - 1].weight = (int)abs(book[where_max - 1].wide - book[where_max].wide);
            else book[where_max - 1].weight = (int)abs(book[where_max - 1].wide - book[where_max - 2].wide) + (int)abs(book[where_max - 1].wide - book[where_max].wide) - (int)abs(book[where_max - 2].wide - book[where_max].wide);
        }
    }
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        ans += (int)abs(book[i].wide - book[i + 1].wide);
    }
    cout << ans;
    return 0;
}