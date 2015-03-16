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
using namespace std;
int gg[1010],ans[1010],a[1010];
struct node
{
	int x1,x2;
}f[1010];
int across(int x1,int y1,int x2,int y2)
{
	return (x1*y2)-(x2*y1);
}
int cmp1(node a,node b)
{
	return a.x1<b.x1;
}
int cmp2(int a,int b)
{
	return a<b;
}
int main()
{
	int n,x1,m,x,y,x2,y1,y2,i,j;
	while (~scanf("%d",&n) && n)
	{
		scanf("%d%d%d%d%d",&m,&x1,&y1,&x2,&y2);
		for (i=0;i<n;i++)
			scanf("%d%d",&f[i].x1,&f[i].x2);
		f[n].x1=x2;f[n].x2=x2;
		sort(f,f+n+1,cmp1);
		memset(ans,0,sizeof(ans));
		memset(gg,0,sizeof(gg));
		memset(a,0,sizeof(a));
		for (i=1;i<=m;i++)
		{
			scanf("%d%d",&x,&y);
			for (j=0;j<=n;j++){
				int k=across(f[j].x1-x,y1-y,f[j].x2-x,y2-y);
				if (k<0){
					ans[j]++;
					break;
				}
			}
		}
		map<int,int>mp;
		int t=0;
		for (i=0;i<=n;i++)
		{
			if (ans[i]>0)
			{
				gg[ans[i]]++;
				if (mp[ans[i]]==0)
				{
					mp[ans[i]]=1;
					a[t++]=ans[i];
				}
			}
		}
		sort(a,a+t,cmp2);
		cout<<"Box"<<endl;
		for (i=0;i<t;i++)
		{
			printf("%d: %d\n",a[i],gg[a[i]]);
		}
	}
	return 0;
}
