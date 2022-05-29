#include<iostream>

using namespace std;

int tr[1000001];
int etop;

void upgrade(int x)
{
    int t=2*x;
    if(t>etop)
        return ;
    if(t<etop&&tr[t]>tr[t+1])
        t++;
    if(tr[x]>tr[t])
    {
        swap(tr[x],tr[t]);
        upgrade(t);
    }
    return ;
}

void downgrade(int e)
{
    while(tr[e]<tr[e/2])
    {
        swap(tr[e],tr[e/2]);
        e/=2;
    }
    return ;
}

void push(int x)
{
    tr[++etop]=x;
    downgrade(etop);
    //cout<<etop<<" "<<tr[etop]<<endl;
    return ;
}

int head()
{
    return tr[1];
}

void pop()
{
    swap(tr[1],tr[etop--]);
    upgrade(1);
    return ;
}

int main()
{
    int n,x,num;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        switch(x)
        {
            case 1:
            {
                 cin>>num;
                 push(num);
                 break;
            }
            case 2:
            {
                cout<<head()<<endl;
                break;
            }
            case 3:
            {
                pop();
                break;
            }
        }
    }
    return 0;
}