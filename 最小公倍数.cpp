#include <stdio.h>
#include <math.h>
int gcd(int a,int b)
{
	return (b==0)?a:gcd(b,a%b);
}
int main()
{
	int n,m; 
	while (~scanf("%d%d",&n,&m))
	{
		int k=gcd(n,m);
		printf("最大公约数=%d\n",k);
		printf("最小公倍数=%d\n",n*m/k);
	}
	return 0;
}
