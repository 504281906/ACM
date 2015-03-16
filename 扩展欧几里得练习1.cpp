#include <iostream>
#include <cstdio>
using namespace std;
int x,y,n,m,k;
int exgcd(int a,int b)
{
	if (!b)
	{
		x=1;
		y=0;
		k=a;
	}
	else
	{
		exgcd(b,a % b);
		int t=x;
		x=y;
		y=t-a/b*y;
	}
}
int main()
{
	while (~scanf("%d%d",&n,&m))
	{
		if (n<m)
		{
			n=n+m;
			m=n-m;
			n=n-m;
		}
		exgcd(n,m);
		printf("%d=%d*%d+%d*%d\n",k,x,n,y,m);
	}
}
