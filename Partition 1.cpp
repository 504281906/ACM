#include <cstdio>
#include <cstring>
#include <algorithm>
#define M 1000000007
int main()
{
	__int64 T,a,b;
	scanf("%I64d",&T);
	while (T--)
	{
		int s=0;
		scanf("%I64d%I64d",&a,&b);
		if (a<b) {printf("0\n");continue;}
		int n=a-b+1;
		if (n<=4)
		{
			switch(n)
			{
			case 1:printf("1\n");continue;
			case 2:printf("2\n");continue;
			case 3:printf("5\n");continue;
			case 4:printf("12\n");continue;
		}}
		int k=(n-2)/2;
		s=2*(k*n*n % M+2*k*(k+1)*(2*k+1)/3 % M)%M-2*(2*k*(k+1)*n)%M;
		s+=n;
		if (s<0) s+=M;
		if (k % 2==1) s+=2;
		printf("%d\n",s);
	}
	return 0;
}
