#include <iostream>
using namespace std;
#define nullptr NULL
struct Node
{
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int data_) : data(data_), next(nullptr) {}
}; //这段结构体定义我们课堂上没有讲过，不过不影响答题，可以理解为这个结构体类型的两个构造函数，C++把结构体和类不太区别

class LinkedList
{
private:
    Node *head;

public:
    LinkedList() { head = new Node; }
    int AddNode(Node *node);
    int DeleteNodeByData(int data);
    void PrintList();
};

int LinkedList::AddNode(Node *node)
{
    Node *cur = head;
    while (cur->next)
    {
        if (cur->next == node)
        {
            return 0;
        }
        cur = cur->next;
    }
    cur->next = node;
    node->next = nullptr;
    return 1;
}

int LinkedList::DeleteNodeByData(int data)
{
    Node *p1;
    Node *cur = head;
    p1 = cur;
    cur = cur->next;
    while (cur)
    {
        // p1 = cur;
        if (cur->data == data)
        {
            break;
        }
        p1 = cur;
        cur = cur->next;
    }
    if (cur == nullptr)
    {
        return 0;
    }
    p1->next = cur->next;
    cur->next = nullptr;
    return 1;
}

void LinkedList::PrintList()
{
    Node *cur = this->head->next;
    while (cur != nullptr)
    {
        cout << cur->data << endl;
        cur = cur->next;
    }
}

int main(int argc, char const *argv[])
{
    LinkedList list;
    int n, d;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> d;
        Node *node = new Node(d);
        list.AddNode(node);
    }
    list.PrintList();
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> d;
        list.DeleteNodeByData(d);
    }
    list.PrintList();
    return 0;
}