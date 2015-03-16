#include<stdio.h>
int main()
{
	__int64 n,k,i,t;
	while(scanf("%I64d%I64d",&n,&k)>0)
	{
		for(i=1;i<=n;i++)
		{
			t=k%2;
			if(t==1)
			{
				printf("%I64d\n",i);
				break;
			}
			else
				k/=2;
		}
	}
	return 0;
}
