#include<iostream>
using namespace std;

int main() {
    int a,b,t;
    cin>>t;
    while(t--) {
        cin>>a>>b;
        if(a==b) cout<<0<<endl;
        else if(a>b) {
            if((a-b)&1) cout<<2<<endl;
            else cout<<1<<endl;
        } else if(a<b) {
            if ((b-a)&1) cout<<1<<endl;
            else if(((b-a)>>1)&1) cout<<2<<endl;
            else cout<<3<<endl;
        }
    }
    return 0;
}