#include<iostream>
#include<algorithm>
#include<cstdlib>

using namespace std;

const int MAXN=100001;

int a[MAXN],b[MAXN];

void update(int x,int y)
{
    int t=2*x;
    if(t>y)
        return ;
    if(t<y&&a[t]>a[t+1])
        t++;
    if(a[x]>a[t])
    {
        swap(a[x],a[t]);
        update(t,y);
    }
    return ;
}

void heapsort(int n)
{
    for(int i=n;i>0;i--)
        update(i,n);
    for(int i=n-1;i>0;i--)
    {
        swap(a[1],a[i+1]);
        update(1,i);
    }
    return ;
}

void mergesort(int l,int r) {
    if(l==r) return ;
    int mid=(l+r)>>1;
    mergesort(l,mid);
    mergesort(mid+1,r);
    int i,j,cnt;
    for(i=l,j=mid+1,cnt=l;i<=mid&&j<=r;) {
        if(a[i]<a[j]) b[cnt++]=a[i++];
        else b[cnt++]=a[j++];
    }
    for(;i<=mid;i++) b[cnt++]=a[i];
    for(;j<=r;j++) b[cnt++]=a[j];
    for(int k=l;k<=r;k++) a[k]=b[k];
    return ;
}

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    mergesort(1,n);
    for(int i=1;i<n;i++)
        cout<<a[i]<<" ";
    cout<<a[n]<<endl;
    heapsort(n);
    for(int i=1;i<n;i++)
        cout<<a[i]<<" ";
    cout<<a[n]<<endl;
    return 0;
}