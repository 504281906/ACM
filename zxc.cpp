#include <cstdio>
#include <iostream>
using namespace std;
int x,y,k;
int exgcd(int a,int b)
{
	if (b==0)
	{
		k=a;
		x=1;
		y=0;
		return 0;
	}
	else
	{
		exgcd(b,a%b);
		int t=x;
		x=y;
		y=t-a/b*y;
	}
}
int main()
{
	int n,m;
	while (~scanf("%d%d",&n,&m))
	{
		if (n<m)
		{
			int t=n;
			n=m;
			m=t;
		}
		exgcd(n,m);
		printf("%d * %d + %d * %d=%d\n",x,n,y,m,k);
	}
	return 0;
} 
