#include <stdio.h>
int main()
{
	int i,s,n;
	while (scanf("%d",&n)!=EOF)
	{
		i=1;s=0;
		while (1)
		{
			if (i<=n) 
			 i=2*i;
			else 
			 i=(i-n-1)*2+1;
			if (i==1)
			 {s++;break;}
			s++;
		}
		printf("%d\n",s);
	}
	return 0;
}
