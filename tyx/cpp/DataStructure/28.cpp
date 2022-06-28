#include <iostream>

using namespace std;

const int p = 13;

bool hash1(int key, int tmp);
bool hash2(int key, int tmp);
bool link(int key, int tmp);

typedef struct _node {
    struct _node* next;
    int value;
} Node;

int n;
int h[100], h2[100];
Node* l[100];

int main() {
    cin >> n;
    for (int i = 0; i < p; i++) {
        l[i] = new Node;
        l[i]->next = NULL;
        l[i]->value = 0;
    }
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        int key = tmp % p;
        bool flag = hash1(key, tmp);
        // cout << key << ' ';
        if (!flag) {
            cout << "hash1: " << key << ' ' << tmp << endl;
        }
        flag = hash2(key, tmp);
        if (!flag) {
            cout << "hash2: " << key << ' ' << tmp << endl;
        }
        flag = link(key, tmp);
        if (!flag) {
            cout << "link: " << key << ' ' << tmp << endl;
        }
    }
    int ans = 0;
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < p; j++) {
            if (h[(i + j) % p] == 0) {
                ans += j + 1;
                break;
            }
        }
    }
    cout << (double)ans / p << endl;
    ans = 0;
    for (int i = 0; i < p; i++) {
        for (int j = 1; j <= 2 * n + 1; j++) {
            int pos = (i + (j / 2) * (j / 2) * (int)pow(-1, j & 1)) % p;
            if (h2[pos] == 0) {
                ans += j;
                break;
            }
        }
    }
    cout << (double)ans / p << endl;
    ans = 0;
    for (int i = 0; i < p; i++) {
        Node* pos = l[i];
        while (pos->next != NULL) {
            pos = pos->next;
            ans++;
        }
    }
    cout << (double)ans / p << endl;
    return 0;
}

bool hash1(int key, int tmp) {
    for (int i = 0; i < n; i++) {
        int pos = (key + i) % p;
        if (h[pos] == 0) {
            h[pos] = tmp;
            return true;
        }
    }
    return false;
}

bool hash2(int key, int tmp) {
    for (int i = 1; i <= 2 * n + 1; i++) {
        int pos = (key + (i / 2) * (i / 2) * (int)pow(-1, i & 1)) % p;
        if (h2[pos] == 0) {
            h2[pos] = tmp;
            return true;
        }
    }
    return false;
}

bool link(int key, int tmp) {
    Node* pos = l[key];
    while (pos->next != NULL) pos = pos->next;
    pos->next = new Node;
    pos = pos->next;
    pos->next = NULL;
    pos->value = tmp;
    return true;
}