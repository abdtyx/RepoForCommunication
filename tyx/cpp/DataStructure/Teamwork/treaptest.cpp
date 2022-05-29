#include"treap.hpp"

bool cmp(int x,int y) {
    return x<y;
}

int main() {
    srand(20021003);
    treap<int> t(cmp);
    int n;
    cin>>n;
    for(int i=0,x;i<n;i++) {
        cin>>x;
        t.insert(x);
    }
    t.output();
    return 0;
}