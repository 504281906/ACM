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
int n,a[M+5],p[M+5],c[M+5];
void init()
{
	int b[100];
	int cnt=0;
	scanf("%d",&n);
	memset(c,0,sizeof(c));
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		int k=a[i];
		cnt=0;
		for (int j=1;p[j]*p[j]<=k;j++)
		{
			if (k % p[j]==0)
			{
				b[cnt++]=p[j];
				while (k % p[j]==0) 
					k/=p[j];
			}
		}
		if (k!=1)
			b[cnt++]=k;
		for (int j=1;j<(1<<cnt);j++)
		{
			int s=1;
			for (int l=0;l<cnt;l++)
			{
				if (j & (1<<l))
					s*=b[l];
			}
			c[s]++;
		}
	}
}
void solve()
{
	LL ans=n;
	ans=ans*(n-1)*(n-2)/6;
	LL sum=0;
	for (int i=1;i<=n;i++)
	{
		int k=a[i];
		int b[100];
		int cnt=0;
		LL ret=0;
		for (int j=1;p[j]*p[j]<=k;j++)
		{
			if (k % p[j]==0)
			{
				b[cnt++]=p[j];
				while (k % p[j]==0)
					k/=p[j];
			}
		}
		if (k!=1)
			b[cnt++]=k;
		for (int j=1;j<(1<<cnt);j++)
		{
			int gg=0;
			int s=1;
			for (int l=0;l<cnt;l++)
			{
				if (j & (1<<l))
				{
					gg++;
					s*=b[l];
				}
			}
			if (gg % 2==1) ret+=c[s];
			else ret-=c[s];
		}
		if (ret==0) continue;
		sum+=(ret-1)*(n-ret);
		//cout<<i<<"  "<<ret<<"  "<<sum<<endl;
	}
	cout<<ans - sum/2<<endl;
}
int main()
{
	int T;
	//freopen("out1.txt","w",stdout);
	scanf("%d",&T);
	memset(p,0,sizeof(p));
	memset(a,0,sizeof(a));
	int t=0;
	for (int i=2;i<=M;i++)
	{
		if (!a[i])
			p[++t]=i;
		for (int j=1;p[j]!=0&&(n=p[j]*i)<M;j++)
		{
			a[n]=1;
			if (i % p[j]==0) break;
		}
	}
	while (T--)
	{
		init();
		solve();
	}
	return 0;
}
