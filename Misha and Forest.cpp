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
	int id;
	int b;
	int s;
	node (){};
	node (int a,int b,int c):id(a),b(b),s(c){}
	bool operator <(node a)const {
		b<a.b;
	} 
}f[80000];
struct node1{
	int a,b;
}g[80000];
int main(){
	int n,i;
	while (~scanf("%d",&n)){
		priority_queue<node>q;
		for (i=0;i<n;i++){
			scanf("%d %d",&f[i].b,&f[i].s);
			f[i].id=i;
			if (f[i].b==1) q.push(f[i]);
		}
		int gg=0;
		while (!q.empty()){
			node d=q.top();
			q.pop();
			if (d.b==0) continue;
			if (f[d.id].b==0) continue;
			gg++;
			g[gg].a=d.id;
			g[gg].b=d.s;
			f[d.s].b--;
			f[d.s].s^=d.id;
			if (f[d.s].b==1) q.push(f[d.s]);
		}
		cout<<gg<<endl;
		for (i=1;i<=gg;i++)
			cout<<g[i].a<<" "<<g[i].b<<endl;
	}
	return 0;
}
