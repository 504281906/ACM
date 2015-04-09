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
	int s,l,r;
}a[500010];
void bulit(int n,int l,int r)
{
	a[n].s=0;
	a[n].l=l;
	a[n].r=r;
	if (l==r) return; 
	int m=(l+r)/2;
	bulit(n*2,l,m);
	bulit(n*2+1,m+1,r);
}
void insert(int n,int x,int y)
{
	a[n].s+=y;
	if (a[n].l==a[n].r)
		return;
	int m=(a[n].l+a[n].r)/2;
	if (x<=m)
		insert(n*2,x,y);
	else
		insert(n*2+1,x,y);
}
void change(int n,int x,int y)
{
	if (a[n].l==a[n].r)
	{
		a[n].s+=y;
		return;
	}
	int m=(a[n].l+a[n].r)/2;
	if (x<=m)
		change(n*2,x,y);
	else 
		change(n*2+1,x,y);
	a[n].s=a[2*n].s+a[2*n+1].s;
}
long long qsum(int n,int l,int r)
{
	if (a[n].l==l && a[n].r==r)
		return a[n].s;
	int m=(a[n].l+a[n].r)/2;
	if (r<=m)
		return qsum(n*2,l,r);
	else if (l>m)
		return qsum(n*2+1,l,r);
	else
		return qsum(n*2,l,m)+qsum(n*2+1,m+1,r);
}
int main()
{
	int T,n,i,j,k;
	char c[10];
	scanf("%d",&T);
	for (int cas=1;cas<=T;cas++)
	{
		printf("Case %d:\n",cas);
		scanf("%d",&n);
		bulit(1,1,n);
		for (i=1;i<=n;i++)
		{
			scanf("%d",&k);
			insert(1,i,k);
		}
		while (~scanf("%s",&c))
		{
			if (c[0]=='E') break;
			scanf("%d%d",&i,&j);
			if (c[0]=='A') change(1,i,j);
			if (c[0]=='S') change(1,i,-j);
			if (c[0]=='Q') printf("%lld\n",qsum(1,i,j));
		}
	}
	return 0;
}

