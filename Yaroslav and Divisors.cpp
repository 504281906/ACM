#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#define M 200010
using namespace std;
struct node
{
	int l,r,id;
	bool operator <(const node &k)const
	{
		return l<k.l;
	}
}q[M],q1[M];
int f[M],a[M],ans[M];
int n,m;
int low(int x)
{
	return (x & (-x));
}
int sum(int x)
{
	int s=0;
	while (x>0)
	{
		s+=f[x];
		x-=low(x);
	}
	return s;
}
void updata(int x,int k)
{
	while (x<=n)
	{
		f[x]+=k;
		x+=low(x);
	}
}
int main()
{
	int i,j,k;
	int pos[M];
	memset(f,0,sizeof(f));
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		pos[a[i]]=i;
	}
	for (i=1;i<=m;i++)
	{
		scanf("%d%d",&q[i].l,&q[i].r);
		q1[i].r=q[i].l;
		q1[i].l=q[i].r;
		q[i].id=q1[i].id=i;
	}
	sort(q+1,q+m+1);
	sort(q1+1,q1+m+1);
	for (i=1,j=1,k=1;i<=n;i++)
	{
		while (j<=m && q[j].l==i)
		{
			ans[q[j].id]-=sum(q[j].r)-sum(q[j].l-1);
			j++;
		}
		for (int ii=a[i];ii<=n;ii+=a[i]) updata(pos[ii],1);
		while (k<=m && q1[k].l==i)
		{
			ans[q1[k].id]+=sum(q1[k].l)-sum(q1[k].r-1);
			k++;
		}
	}
	for (i=1;i<=m;i++)
		printf("%d\n",ans[i]);
	return 0;
}
