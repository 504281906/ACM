#include<stdio.h>
int main()
{
	__int64 i,n;
	__int64 sum[100001];
	sum[0]=0;
for(i=1;i<=100000;i++)
{
	if(i%3==0)
		sum[i]=sum[i-1]+i*i*i;
	else 
		sum[i]=sum[i-1]+i;
}
while (scanf("%I64d",&n)!=EOF&&n>=0)
		{
			printf("%I64d\n",sum[n]);
	    }
	return 0;
}
