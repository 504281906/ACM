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
		printf("���Լ��=%d\n",k);
		printf("��С������=%d\n",n*m/k);
	}
	return 0;
}
