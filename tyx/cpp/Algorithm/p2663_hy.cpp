#include<iostream>
using namespace std;
const int maxn=1e4+2;

bool d[105][10005];
int a[105],n,sum;

int main() {
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        sum+=a[i];
    }
    d[0][0]=1;
    for(int j=1;j<=n;j++) {//the last one
        for(int i=n;i;i--)//num of used stus
            for(int s=a[j];s<=sum/2;s++) d[i][s]=d[i][s]||d[i-1][s-a[j]];
    }
    for(int i=sum/2;~i;i--) {
        if(d[n>>1][i]) {
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}