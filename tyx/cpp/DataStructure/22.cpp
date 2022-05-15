#include <iostream>
#include <queue>

using namespace std;

typedef struct _Node {
    int x;
    struct _Node* ls;
    struct _Node* rs;
    // bool operator>(struct _Node b) {
    //     return x > b.x;
    // }
    friend bool operator>(struct _Node a, struct _Node b) {
        return a.x > b.x;
    }
} Node;

void print(Node node, int layer, string h_code);

// struct mycmp {
//     bool operator() (Node& a, Node& b) {
//         return a.x < b.x;
//     }
// };
string out;
string Huffman_code;
int ans;

int main() {
    priority_queue<Node, vector<Node>, greater<Node> > h;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        Node* node = new Node;
        node->ls = NULL;
        node->rs = NULL;
        cin >> node->x;
        h.push(*node);
    }
    while (h.size() > 1) {
        Node a = h.top();
        h.pop();
        Node b = h.top();
        h.pop();
        Node* fa = new Node;
        fa->ls = new Node;
        fa->rs = new Node;
        fa->ls->x = a.x;
        fa->ls->ls = a.ls;
        fa->ls->rs = a.rs;
        fa->rs->x = b.x;
        fa->rs->ls = b.ls;
        fa->rs->rs = b.rs;
        fa->x = a.x + b.x;
        Node f = *fa;
        h.push(f);
    }
    Node head = h.top();
    string h_code;
    out.clear(); 
    h_code.clear();
    Huffman_code.clear();
    print(head, 0, h_code);
    cout << ans << endl << out << endl << Huffman_code;
}

void print(Node node, int layer, string h_code) {
    if (node.ls == NULL) {
        char b[1000];
        out += string(itoa(node.x, b, 10));
        ans += node.x * layer;
        Huffman_code += h_code + " ";
        return;
    }
    char buf[1000];
    out += string(itoa(node.x, buf, 10));
    out.push_back('(');
    string tmp_code = h_code;
    tmp_code.push_back('0');
    print(*node.ls, layer + 1, tmp_code);
    out.push_back(',');
    h_code.push_back('1');
    print(*node.rs, layer + 1, h_code);
    out.push_back(')');
    return;
}