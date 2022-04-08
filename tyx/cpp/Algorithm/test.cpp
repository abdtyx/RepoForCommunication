#include<cstdio>
#include<iostream>
#include<algorithm>           //包含sort
#include <queue>
using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int> > q;
    q.push(4);
    q.push(2);
    cout << q.top();
}