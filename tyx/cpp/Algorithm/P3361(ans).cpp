#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<time.h>
using namespace std;
/* P3361 cool loves maids 题解

*/

int n,rxa,rxc,rya,ryc,rza,rzc,rp=2333333,i,j,k,l,f[45][45];
long long x,y,z,arr;
double xxx,yyy,a[45][45],b[45][45],ans;//注意:每个妹子的坐标是实数,所以要用double
int main(){
    cin>>n>>rxa>>rxc>>rya>>ryc>>rza>>rzc;//生成数据:读入
    for(i=1;i<=2*n;i++){
        x=(y*rxa+rxc)%rp;
        y=(z*rya+ryc)%rp;
        z=(x*rza+rzc)%rp;//你怎么讲我怎么写
        if(i%2==1){
            xxx=(double)(x%20)+(double)((double)(y%10)/10.0)+(double)((double)(z%10)/100.0);//生成的每个妹子的横坐标
        }
        else{
            yyy=(double)(x%20)+(double)((double)(y%10)/10.0)+(double)((double)(z%10)/100.0);//生成的每个妹子的纵坐标
            a[(int)xxx][(int)yyy]+=xxx;//此妹子所属楼的横坐标加上此妹子的横坐标
            b[(int)xxx][(int)yyy]+=yyy;//此妹子所属楼的纵坐标加上此妹子的纵坐标
            f[(int)xxx][(int)yyy]++;//此妹子所属楼的妹子数+1
            // cout << xxx << ' ' << yyy << endl;
/* 另:当且仅当[x]=i, [y]=j时,妹子(x,y)属于楼(i,j) i,j均为实数

*/

        }
    }
    for(i=0;i<=20;i++){//枚举每栋楼
        for(j=0;j<=20;j++){
            for(k=i+1;k<=20;k++){//枚举与现在枚举到的楼不在同一行或是同一列的楼
                for(l=j+1;l<=20;l++){
                    ans+=(a[k][l]+b[k][l])*(double)f[i][j]-(a[i][j]+b[i][j])*(double)f[k][l];//分子:将两栋楼中所有妹子的坐标*其妹子总数,用曼哈顿距离一下算出所有妹子的距离
                    arr+=f[i][j]*f[k][l];//分母:两两结合,所以将两栋楼中的妹子数相乘
                }
            }
        }
    }
    printf("%.5f",ans/arr);//平均值,分子/分母
    return 0;//结束
}