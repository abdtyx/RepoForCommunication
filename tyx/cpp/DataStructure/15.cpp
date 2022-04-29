#include <iostream>

using namespace std;

typedef struct _Node {
    int num;
    struct _Node* next;
} Node;

int main() {
    int n;
    cin >> n;
    Node* head = new Node;
    int sum = 1;
    head->num = 0;
    Node* cur = head;
    while (sum != n + 1) {
        Node* son = new Node;
        cur->next = son;
        son->num = sum++;
        if (son->num == n) {son->next = NULL;}
        cur = son;
    }
    for (int i = 0; n > 3; i++) {
        cur = head;
        Node* lst = NULL;
        int ctr = 0;
        while (cur->next != NULL) {
            lst = cur;
            cur = cur->next;
            ctr++;
            if (ctr % ((i & 1) + 2) == 0) {
                lst->next = cur->next;
                n--;
            }
        }
    }
    cur = head;
    while (cur->next != NULL) {
        cur = cur->next;
        cout << cur->num;
        if (cur->next != NULL) cout << ' ';
    }
    return 0;
}