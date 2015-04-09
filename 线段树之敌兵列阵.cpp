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
//#define DEBUG
struct node
{
	int sum,l,r;
}a[500010];
void bulit(int n,int l,int r)
{
	a[n].sum=0;
	a[n].l=l;
	a[n].r=r;
	if (l==r) return;
	int mid=(l+r)/2;
	bulit(n*2,l,mid);
	bulit(n*2+1,mid+1,r);
}
void insert(int n,int x,int y)
{
	a[n].sum+=y;
	if (a[n].l==a[n].r)
		return;
	int mid=(a[n].l+a[n].r)/2;
	if (x<=mid)
		insert(n*2,x,y);
	else
		insert(n*2+1,x,y);
}
void change(int n,int x,int y)
{
	if (a[n].l==a[n].r)
	{
		a[n].sum+=y;
		return;
	}
	int mid=(a[n].l+a[n].r)/2;
	if (x<=mid)
		change(n*2,x,y);
	else 
		change(n*2+1,x,y);
	a[n].sum=a[n*2].sum+a[n*2+1].sum;
}
long long qsum(int n,int l,int r)
{
	if (a[n].l==l && a[n].r==r)
		return a[n].sum;
	int mid=(a[n].l+a[n].r)/2;
	if (r<=mid)
		return qsum(n*2,l,r);
	else if (l>mid)
		return qsum(n*2+1,l,r);
	else return qsum(n*2,l,mid)+qsum(n*2+1,mid+1,r);
}
int main()
{
	int T,n,i,k,j;
	char s[10];
	scanf("%d",&T);
	int t=1;
	while (T--)
	{
		printf("Case %d:\n",t++);
		scanf("%d",&n);
		bulit(1,1,n);
		//memset(f,0,sizeof(f));
		for (i=1;i<=n;i++)
		{
			scanf("%d",&k);
			insert(1,i,k);
		}
		getchar();
		while (~scanf("%s",&s))
		{
			if (s[0]=='E') break;
			scanf("%d%d",&i,&j);
			if (s[0]=='A') change(1,i,j);
			if (s[0]=='S') change(1,i,-j);
			if (s[0]=='Q') printf("%lld\n",qsum(1,i,j));
		}
	}
	return 0;
}
