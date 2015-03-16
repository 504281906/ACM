#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
struct node
{
	string s;
	int k;
};
int a[10];
bool vis[5010];
int main()
{
	int n,m;
	while (~scanf("%d",&n))
	{
		int i,j;
		bool flag=false;
		scanf("%d",&m);
		for (i=0;i<m;i++)
			scanf("%d",&a[i]);
		if (n==0) 
		{
			printf("0\n");
			continue;
		}
		sort(a,a+m);
		memset(vis,true,sizeof(vis));
		queue< node > q;
		for (i=0;i<m;i++)
		{
			int yu=a[i] % n;
			node f;
			if (!vis[yu]) continue;
			string s1;
			s1.append(1,(char)(a[i]+'0'));
			if (s1=="0") continue;
			vis[yu]=false;
			f.s=s1;f.k=yu;
			q.push(f);
		}
		while (!q.empty())
		{
			node f=q.front();
			q.pop();
			if (f.k==0)
			{
				cout<<f.s<<endl;
				flag=true;
				break;
			}
			for (i=0;i<m;i++)
			{
				int yu=(f.k*10+a[i]) %n;
				if (!vis[yu]) continue;
				string s1=f.s;
				s1.append(1,(char)(a[i]+'0'));
				vis[yu]=false;
				q.push(node({s1,yu}));
			}
		}
		if (!flag) cout<<0<<endl;
	}
	return 0;
}
