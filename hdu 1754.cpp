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
using namespace std;
struct node
{
	int max,l,r;
}a[2000005];
int s;
void bulit(int n,int l,int r)
{
	a[n].max=0;
	a[n].l=l;
	a[n].r=r;
	if (l==r) return;
	int mid=(l+r)/2;
	bulit(n*2,l,mid);
	bulit(n*2+1,mid+1,r);
}
void insert(int n,int x,int y)
{
	if (a[n].max<y)
		a[n].max=y;
	if (a[n].l==a[n].r)
		return;
	int mid=(a[n].l+a[n].r)/2;
	if (x<=mid)
		insert(n*2,x,y);
	else
		insert(n*2+1,x,y);
	a[n].max=max(a[n*2].max,a[n*2+1].max);
}
int qmax(int n,int l,int r)
{
	if (a[n].l==l && a[n].r==r)
	{
		if (s<a[n].max)
			s=a[n].max;
		return s;
	}
	int mid=(a[n].l+a[n].r)/2;
	if (r<=mid)
		return qmax(n*2,l,r);
	else if (l>mid) 
		return qmax(n*2+1,l,r);
	else
		return max(qmax(n*2,l,mid),qmax(n*2+1,mid+1,r));
}
int main()
{
	int n,m,i,k;
	while (~scanf("%d%d",&n,&m))
	{
		bulit(1,1,n);
		for (i=1;i<=n;i++)
		{
			scanf("%d",&k);
			insert(1,i,k);
		}
		for (i=1;i<=m;i++)
		{
			getchar();
			char c;
			int q,w;
			s=0;
			scanf("%c%d%d",&c,&q,&w);
			if (c=='U') insert(1,q,w);
			if (c=='Q') printf("%d\n",qmax(1,q,w));
		}
	}
	return 0;
}
