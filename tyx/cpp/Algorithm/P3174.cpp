#include<iostream>
#include<vector>
using namespace std;
const int maxn=3e5+10;

vector<int> e[maxn];
int n,m,d0[maxn],d1[maxn],res;

void dfs(int x) {
    for(int i=0;i<e[x].size();i++) {
        int to=e[x][i];
        if(!vis[to]) dfs(to);
        if(d0[to]+1>d0[x]) {
            d1[x]=d0[x];
            d0[x]=d0[to]+1;
        } else if(d0[to]+1>d1[x]) d1[x]=d0[to]+1;
    }

    res[x]=d0[x]+d1[x]+;
    return ;
}

int main() {
    cin>>n>>m;
    for(int i=0,x,y;i<m;i++) {
        cin>>x>>y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs(1);
    cout<<res<<endl;
    return 0;
}