#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
struct node
{
	int zhi;
	int ci;
}a[500010];
int gcd(int a,int b)
{
	return (b==0?a:gcd(b,a % b));
} 
bool zs(int n)
{
	int i;
	if (n==2) return 1;
	for (i=2;i<=sqrt(n)+1;i++)
		if (n % i==0) return 0;
	return 1;
}
int main()
{
	int i,j,n,m,p;
	memset(a,0,sizeof(a));
	for (i=1;i<=500001;i++)
		a[i].zhi=i;
	for (i=2;i<=500000;i++)
	{
		if (zs(i))
		{
			a[i].ci=1;
			for (j=2*i;j<=500000;j+=i)
			{
				while (a[j].zhi % i==0 && a[j].zhi!=0)
				{
					a[j].zhi/=i;
					a[j].ci++;
				}
			}
		}
	}
	int T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d%d",&n,&m,&p);
		if (n>m)
		{
			n=n+m;
			m=n-m;
			n=n-m;
		}
		int t=0;
		for (i=1;i<=n;i++)
		{
			if (a[i].ci<=p) t+=1+2*(m-i);
			else 
			for (j=i+1;j<=m;j++)
			{	
				if (a[j].ci<=p) t+=2;
				else
				if (a[gcd(i,j)].ci<=p) t+=2;
			}
		}
		printf("%d\n",t);
	}
	return 0;
}
