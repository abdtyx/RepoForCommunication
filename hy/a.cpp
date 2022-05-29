#include<iostream>
using namespace std;

void BubbleSort(int a[],int n) {
    for(int i=0;i<n-1;i++) {
        for(int j=0;j<n-i-1;j++) 
            if(a[j]>a[j+1]) swap(a[j],a[j+1]);
    }
    return ;
}

void SelectionSort(int a[],int n) {
    for(int i=0;i<n;i++) {
        int x=a[n-i-1],pos=n-i-1;
        for(int j=0;j<n-i-1;j++) 
            if(x>a[j]) x=a[j],pos=j;
        swap(a[n-i-1],a[pos]);        
    }
    return ;
}

int main() {
    int a[10];
    for(int i=0;i<10;i++) cin>>a[i];
    BubbleSort(a,10);
    cout<<a[0];for(int i=1;i<10;i++) cout<<" "<<a[i];
    cout<<endl;
    SelectionSort(a,10);
    cout<<a[0];for(int i=1;i<10;i++) cout<<" "<<a[i];
    return 0;
}