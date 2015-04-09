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
	int l,r,sum,max;
}a[400010];
void built (int n,int x,int y)
{
	a[n].l=x;
	a[n].r=y;
	a[n].max=0;
	a[n].sum=0;
	if (x==y) return;
	int mid=(x+y)/2;
	built(n*2,x,mid);
	built(n*2+1,mid+1,y);
}
void insert(int n,int x,int y)
{
	a[n].sum+=y;
	if (a[n].max<y)
		a[n].max=y;
	if (a[n].l==a[n].r)
		return;
	if (x<=(a[n].l+a[n].r)/2)
		insert(n*2,x,y);
	else 
		insert(n*2+1,x,y);
}
void change(int n,int x,int y)
{
	if (a[n].l==a[n].r)
	{
		a[n].max=y;
		a[n].sum=y;
		return;
	}
	int mid=(a[n].r+a[n].l)/2;
	if (x<=mid)
		change(n*2,x,y);
	else 
		change(n*2+1,x,y);
	a[n].sum=a[n*2].sum+a[n*2+1].sum;
	a[n].max=max(a[n*2].max,a[n*2+1].max);
}
int qsum(int n,int l,int r)
{
	if (a[n].l==l && r==a[n].r)
		return a[n].sum;
	int mid=(a[n].l+a[n].r)/2;
	if (r<=mid)
		return qsum(n*2,l,r);
	else if (l>mid)
		return qsum(n*2+1,l,r);
	else return qsum(n*2,l,mid)+qsum(n*2+1,mid+1,r);
}
int qmax(int n,int l,int r)
{
	if (a[n].l==l && r==a[n].r)
		return a[n].max;
	int mid=(a[n].l+a[n].r)/2;
	if (r<=mid)
		return qmax(n*2,l,r);
	else if (l>mid)	
		return qmax(n*2+1,l,r);
	else return max(qmax(n*2,l,mid),qmax(n*2+1,mid+1,r));
}
int main()
{
#ifdef DEBUG
	freopen("cin.txt", "r", stdin);
	freopen("cout.txt", "w", stdout);
#endif
	int n,m,q,x,y;
	scanf("%d%d",&n,&m);
	built(1,1,n);
	for (int i=1;i<=n;i++)
	{
		int k;
		scanf("%d",&k);
		insert(1,i,k);
	}
	while (m--)
	{
		scanf("%d%d%d",&q,&x,&y);
		switch (q)
		{
			case 1:
				{
					change(1,x,y);
					break;
				}
			case 2:
				{
					printf("%d\n",qsum(1,x,y));
					break;
				}
			case 3:
				{
					printf("%d\n",qmax(1,x,y));
					break;
				}
		}
	}
	return 0;
}
