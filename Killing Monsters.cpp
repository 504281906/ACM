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
#define LL __int64
#define EPS 1e-8
using namespace std;
int n,b[100010],a[100010],vis[100010];
int lowbit(int x)
{
    return x&(-x);
}
void inc(int x,int k)
{
    while (x<=n)
    {
        b[x]+=k;
        x+=lowbit(x);
    }
}
LL sum(int x)
{
    LL sum=0;
    while (x<=n && !vis[x])
    {
    	vis[x]=1;
        sum+=b[x];
        x+=lowbit(x);
    }
    return sum;
}
int main()
{
	int x,m,l,r,d,k;
	LL h;
	while (~scanf("%d",&n) && n)
	{
		memset(b,0,sizeof(b));
		scanf("%d",&m);
		while (m--)
		{
			scanf("%d%d%d",&l,&r,&d);
			inc(l,d);
			inc(r+1,-d);
		}
		scanf("%d",&k);
		int s=0;
		memset(a,0,sizeof(a));
		for (int i=n;i>=1;i--)
			a[i]+=a[i+1]+sum(i);
		while (k--)
		{
			scanf("%I64d%d",&h,&x);
			if (a[x]<h)
				s++;
		}
		cout<<s<<endl;
	}
	return 0;
}
