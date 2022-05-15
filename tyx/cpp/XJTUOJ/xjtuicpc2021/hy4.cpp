#include<iostream>
using namespace std;

int n,ans[210];

int main() {
    cin>>n;
    for(int i=0,x;i<n;i++) {
        cin>>x;
        ans[x%200]++;
    }
    int res=0;
    for(int i=0;i<200;i++) res+=ans[i]*(ans[i]-1)/2;
    cout<<res;
    return 0;
}