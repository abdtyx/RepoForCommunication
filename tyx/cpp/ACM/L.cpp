#include <bits/stdc++.h>

using namespace std;

long long a[1000005];
int main() {
    // freopen("test.in","r",stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    int ans=0;
    double cavg=a[0];
    for(int i=1;i<n;i++){
        cavg=cavg*(i/double(i+1))+a[i]/double(i+1);
        int j=upper_bound(a,a+i+1,cavg)-a;
        if(a[j]==cavg)
        {
            j++;
        }
        ans=max(ans,i-j+1);
    }
    cout<<ans;
    return 0;
}