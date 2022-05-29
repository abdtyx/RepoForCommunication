#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6 + 10;
typedef pair<int,double> pid;

struct edge {
    int  to;
    double dist;
    edge() {}
    edge(int m,double n):to(m),dist(n) {}
};

priority_queue<pid,vector<pid>,greater<pid> > q;
vector<edge> e[maxn];
int n;
double x[maxn],y[maxn],v1,v2,d[maxn];
bool vis[maxn];

double dst(double m,double n) {
    return sqrt(m*m+n*n);
}

double calc(int m,int n) {
    double dist=dst(x[m]-x[n],y[m]-y[n]);
    if(m) {
        double rn=3*v2;
        if(rn>dist) return dist/v2;
        else return (dist-rn)/v1+3;
    }
    return dist/v1;
}

void adde(int m,int n) {
    e[m].push_back(edge(n,calc(m,n)));
    return ;
} 

void dijkstra() {
    for(int i=1;i<=1+n;i++) d[i]=2147483647;
    for(int i=0;i<e[0].size();i++) {
        d[e[0][i].to]=e[0][i].dist;
        q.push(make_pair(e[0][i].to,e[0][i].dist));
    }
    vis[0]=1;
    while(!q.empty()) {
        int m=q.top().second;q.pop();
        while(vis[m]) {m=q.top().second;q.pop();if(q.size() == 0)break;}
        vis[m]=1;
        for(int i=0;i<e[m].size();i++) {
            int to=e[m][i].to;
            if(d[to]>d[m]+e[m][i].dist) {d[to]=d[m]+e[m][i].dist;q.push(make_pair(d[to],to));}     
        }
    }
    return ;
}

int main() {
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>x[i]>>y[i];
    }
    cin>>x[0]>>y[0]>>x[n+1]>>y[n+1];
    cin>>v1>>v2;
    adde(0,n+1);
    for(int i=1;i<=n;i++) {
        adde(0,i);
        adde(i,n+1);
        for(int j=i+1;j<=n;j++) {
                adde(i,j);
                adde(j,i);
        }
    }
    dijkstra();
    cout<< fixed << setprecision(10) << d[n+1]<<endl;
    return 0;
}