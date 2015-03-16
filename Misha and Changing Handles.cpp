#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
#include <map>
#include <stack>
#include <list>
#include <vector>
#include <ctime>
#define LL __int64
#define eps 1e-8
#define pi acos(-1)
using namespace std;
struct node{
	string s;
	string ss;
}f[1111];
int cmp(node a,node b){
	return a.s<b.s;
}
int main(){
	int n,i,j;
	while (~scanf("%d",&n)){
		int s=0;
		for (i=1;i<=n;i++){
			string g,gg;
			cin>>g>>gg;
			int flag=1;
			for (j=1;j<=s;j++)
				if (f[j].ss==g){
					f[j].ss=gg;
					flag=0;
					break;
				}
			if (flag){
				s++;
				f[s].s=g;
				f[s].ss=gg;
			}
		}
		sort(f+1,f+s+1,cmp);
		cout<<s<<endl;
		for (i=1;i<=s;i++)
			cout<<f[i].s<<" "<<f[i].ss<<endl;
	}
	return 0;
}
