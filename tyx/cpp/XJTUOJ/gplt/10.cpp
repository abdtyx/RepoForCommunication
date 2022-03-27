#include <bits/stdc++.h>

using namespace std;

typedef struct _Node {
    int num;    // 是门，门后面的数字
    struct _Node* last;
    struct _Node* next[105];    // 子结点 next[0]不用
    bool isworld;   // 是不是新的世界
    bool ishead;    // 是不是头
    int ctr;        // 多少个元素
} Node;

void inser(Node* node, Node* ins, int pos) {
    // 把ins插到node的pos位置
    for (int i = node->ctr; i >= pos + 1; i--) {
        node->next[i + 1] = node->next[i];
    }
    node->ctr++;
    node->next[pos + 1] = ins;
}

void dlt(Node* node, int pos) {
    for (int i = pos; i < node->ctr; i++) {
        node->next[i] = node->next[i + 1];
    }
    node->ctr--;
}

int main() {
    Node* Head = new Node;
    Head->ctr = 0;
    Head->num = 0;
    Head->isworld = true;
    Head->ishead = true;
    int n;
    cin >> n;
    Node* cur = Head;
    for (int i = 0; i < n; i++) {
        int command;
        cin >> command;
        // switch (command) {
            if (command == 1) {
                int a, b;   // a is pos
                cin >> a >> b;
                Node* nd = new Node;
                if (b == 0) {
                    nd->last = cur;
                    nd->ctr = 0;
                    nd->isworld = true;
                    nd->ishead = false;
                    nd->num = 0;
                }
                else {
                    nd->last = cur;
                    nd->ctr = 0;
                    nd->isworld = false;
                    nd->ishead = false;
                    nd->num = b;
                }
                inser(cur, nd, a);
                // break;
            }
            if (command == 2) {
                int a;
                cin >> a;
                dlt(cur, a);
                // break;
            }
            if (command == 3) {
                int a;
                cin >> a;
                if (cur == Head && a == 0) {
                    // break;
                    continue;
                }
                if (a == 0) {
                    cur = cur->last;
                    continue;
                }
                if (cur->next[a]->num != 0) {
                    continue;
                }
                if (cur->next[a]->isworld) {
                    cur = cur->next[a];
                }
                // break;
            }
            if (command == 4) {
                cout << '{';
                for (int j = 1; j <= cur->ctr; j++) {
                    if (cur->next[j]->isworld) {
                        cout << "[]";
                    }
                    else {
                        cout << cur->next[j]->num;
                    }
                    if (j != cur->ctr) {
                        cout << ' ';
                    }
                }
                cout << '}' << endl;
                // break;
            }
    }
    return 0;
}