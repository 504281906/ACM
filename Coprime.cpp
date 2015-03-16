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
#define M 100005
using namespace std;
bool vis[M];
int f[100],t;
int gg[M],sy[M],sg,yz,ans[M],a[M];
map<int,int>mmp;
map<int,int>map1;
int find(int x)
{
	int tt=0,i;
	for (i=1;i<=t;i++)
	{
		if (x==1) return tt;
		if (x % f[i]==0)
		{
			tt++;
			x/=f[i];
		}
	}
	return tt;
}
void go(int x)
{
	int ss[100];
	int gs=0,i;
	int xx=1;
	memset(vis,0,sizeof(vis));
	for (i=1;i<=t;i++)
	{
		if (f[i]>x) break;
		if (x % f[i]==0)
		{
			if (mmp[f[i]]==0)
			{
				gg[++sg]=f[i];
				mmp[f[i]]=1;
			}
			if (map1[f[i]]==0)
			{
				sy[++yz]=f[i];
				map1[f[i]]=1;
			}
			ss[++gs]=f[i];
			vis[f[i]]=1;
			ans[f[i]]++;
			xx*=f[i];
		}
	}
	queue<int>q;
	if (vis[xx]==0)
	{
		ans[xx]++;
		vis[xx]=1;
	}
	q.push(xx);
	while (!q.empty())
	{
		int k=q.front();
		q.pop();
		for (i=1;i<=gs;i++)
		{
			if (k % ss[i]==0)
			{
				if (vis[k/ss[i]]==0)
				{
					q.push(k/ss[i]);
					ans[k/ss[i]]++;
				}
				if (map1[k/ss[i]]==0)
				{
					map1[k/ss[i]]=1;
					sy[++yz]=k/ss[i];
				}
			}
		}
	}
	return;
}
int c[M];
int main()
{
	int T,i,j,n;
	scanf("%d",&T);
	c[0]=0;c[1]=0;c[2]=0;
	for (i=3;i<=M;i++)
		c[i]=i*(i-1)*(i-2)/6;
	int t=0;
	memset(a,0,sizeof(a));
	memset(f,0,sizeof(f));
	for (i=2;i<=M;i++)
	{
		if (!a[i])
			f[++t]=i;
		for (j=1;f[j]!=0 && (n=f[j]*i)<M;j++)
		{
			a[n]=1;
			if (i % f[j]==0) break;
		}
	}
	while (T--)
	{
		int tp=0;
		mmp.clear();
		map1.clear();
		memset(gg,0,sizeof(gg));
		memset(sy,0,sizeof(sy));
		memset(ans,0,sizeof(ans));
		scanf("%d",&n);
		sg=0;
		yz=0;
		map1[1]=1;
		for (i=1;i<=n;i++)
		{
			int k;
			scanf("%d",&k);
			if (k==1) 
			{
				tp=1;
				continue;
			}
			go(k);
		}
		LL yy=0;
		for (i=1;i<=yz;i++)
		{
			if (find(sy[i])%2==1) yy+=c[ans[sy[i]]];
			else yy-=c[ans[sy[i]]];
		}
		int cas=c[sg];
		int q=1,w=2,e=3;
		int a1,a2,a3;
		while (cas--)
		{
			a1=ans[gg[q]]-ans[gg[q]*gg[w]]-ans[gg[q]*gg[e]]+ans[gg[q]*gg[w]*gg[e]];
			a2=ans[gg[w]]-ans[gg[q]*gg[w]]-ans[gg[w]*gg[e]]+ans[gg[q]*gg[w]*gg[e]];
			a3=ans[gg[e]]-ans[gg[q]*gg[e]]-ans[gg[w]*gg[e]]+ans[gg[q]*gg[w]*gg[e]];
			if (a1<=0 || a2<=0 || a3<=0) yy=yy;
			else yy+=a1*a2*a3;
			e++;
			if (e>sg) 
			{
				w++;
				if (w>sg)
				{
					q++;
					w=q+1;
					e=q+2;
				}
				else 
				e=w+1;
			}
		}
	//	cout<<yy<<endl;
		int r=0;
		int z[100];
		memset(z,0,sizeof(z));
		if (tp)
		{
			cas=sg*(sg-1)/2;
			q=1,w=2;
			while (cas--)
			{
				a1=ans[gg[q]]-ans[gg[q]*gg[w]];
				a2=ans[gg[w]]-ans[gg[q]*gg[w]];
				for (i=1;i<=r;i++)
					a2-=ans[gg[w]*z[i]];
				z[++r]=gg[w];
				if (a1<=0 || a2<=0) yy=yy;
				else yy+=a1*a2;
				w++;
				if (w>sg)
				{
					q++;
					w=q+1;
				}
			}
		}
		cout<<yy<<endl;
	}
	return 0;
}
