#include <iostream>
using namespace std;
#define nullptr NULL
struct Node {
int data;
Node* next;
Node() : data(0), next(nullptr) {}
Node(int data_) : data(data_), next(nullptr) {}
}; //这段结构体定义我们课堂上没有讲过，不过不影响答题，可以理解为这个结构体类型的两个构造函数，C++把结构体和类不太区别

class LinkedList {
private:
Node* head;
public:
LinkedList() {head = new Node;}
int AddNode(Node* node);
int DeleteNodeByData(int data);
void PrintList();
};

int LinkedList::AddNode(Node* node)
{
    Node* cur = this->head->next;
    Node* lst = this->head;
    if (cur == NULL) {
        this->head->next = node;
        return 1;
    }
    while (cur != NULL) {
        if (node->data > cur->data) {
            if (cur->next == NULL) {
                cur->next = node;
                return 1;
            }
            lst = cur;
            cur = cur->next;
            continue;
        }
        else if (node->data == cur->data) return 0;
        else if (node->data < cur->data) {
            lst->next = node;
            node->next = cur;
            // node->next = cur->next;
            // cur->next = node;
            return 1;
        }
    }
    // 一般不可能到这一步
    return -1;
}

int LinkedList::DeleteNodeByData(int data)
{
    Node* cur = this->head->next;
    Node* lst = this->head;
    while (cur != NULL) {
        if (data > cur->data) {
            lst = cur;
            cur = cur->next;
            continue;
        }
        else if (data == cur->data) {
            lst->next = cur->next;
            delete cur;
            return 1;
        }
        else if (data < cur->data) {
            return 0;
        }
    }
    // 一般不可能到这一步
    return -1;
}

void LinkedList::PrintList()
{
Node* cur = this->head->next;
while (cur != nullptr) {
cout << cur->data << endl;
cur = cur->next;
}
}

int main(int argc, char const *argv[])
{
LinkedList list;
int n, d;
cin >> n;
for (int i=0; i<n; i++) {
cin >> d;
Node* node = new Node(d);
list.AddNode(node);
}
list.PrintList();
cin >> n;
for (int i=0; i<n; i++) {
cin >> d;
list.DeleteNodeByData(d);
}
list.PrintList();
return 0;
}