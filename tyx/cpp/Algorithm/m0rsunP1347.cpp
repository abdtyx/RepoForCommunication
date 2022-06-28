#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<string>
#include<queue>
using namespace std;

const int maxn=27;

int n,m,du[maxn],dun[maxn],res[maxn],cnt,f[maxn];
string s;
queue<int> q;
vector<int> e[maxn];

int find(int x) {
	return f[x]==x?f[x]:f[x]=find(f[x]);
}

void adde(int x,int y) {
	f[find(x)]=find(y);
	//cout<<find(x)<<" "<<find(y)<<endl;
	du[y]++;
	e[x].push_back(y);
	return ;
}

int toposort() {
	memset(dun,0,sizeof(dun));
	memset(res,0,sizeof(res));
	while(!q.empty()) q.pop();
	cnt=0;
	bool pan=1;
	//cout<<"msre "<<du[0]<<" "<<du[1]<<" "<<du[2]<<" "<<du[3]<<endl;
	for(int i=0;i<n;i++) if(!du[i]) q.push(i);
	//cout<<"mswa "<<q.size()<<endl;
	while(!q.empty()) {
		int x=q.front(),cnt2=0;
		//cout<<x<<endl;
		res[cnt++]=x;
		q.pop();
		for(int i=0,sz=e[x].size();i<sz;i++) {
			if(e[x][i]==x) return 2;
			dun[e[x][i]]++;
			if(du[e[x][i]]==dun[e[x][i]]) q.push(e[x][i]),cnt2++;//,cout<<e[x][i]<<" "<<du[e[x][i]]<<endl;
		}
		if(cnt2>1) {
			//cout<<"msuke "<<cnt2<<endl;
			pan=0;
		}
	}
	//cout<<cnt<<endl;
	for(int i=0;i<n;i++) if(du[i]!=dun[i]) {
		//cout<<i<<" "<<du[i]<<" "<<dun[i]<<endl;
		return 2;}
	//cout<<"msmle "<<cnt<<endl;
	if(cnt<n) pan=0;
	//cout<<"mswa"<<endl;
	for(int i=0;i<n;i++) if(find(i)!=find(0)) {
		//cout<<"msmemsettle "<<i<<" "<<find(i)<<" "<<find(0)<<endl;
		pan=0;
	}
	return pan;
}

int main() {
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) f[i]=i;
	for(int i=0;i<m;i++) {
		cin>>s;
		adde(s[0]-'A',s[2]-'A');
		int t=toposort();
		if(t==1) {
			printf("Sorted sequence determined after %d relations: ",i+1);
			for(int j=0;j<cnt;j++) printf("%c",res[j]+'A');
			printf(".\n");
			return 0;
		}
		else if(t==2) {
			printf("Inconsistency found after %d relations.\n",i+1);
			return 0;
		}
	}
	printf("Sorted sequence cannot be determined.\n");
	//cout<<endl;
	//for(int i=0;i<n;i++) cout<<find(i)<<endl;
	//cout<<endl;
	//for(int i=0;i<n;i++) {
		//for(int j=0,sz=e[i].size();j<sz;j++) cout<<e[i][j]<<" ";
		//cout<<endl;
	//}
	return 0;
}