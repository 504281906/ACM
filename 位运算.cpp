#include <stdio.h>
int main()
{
	int a1[20],a2[20],a3[20],a4[20],t1=0,t2=0,t3=0,t4=0,i;
	for (i=0;i<=16;i++)
	{
		if (i&1)
			a1[t1++]=i;
		if (i&2)
			a2[t2++]=i;
		if (i&4)
			a3[t3++]=i;
		if (i&8)
			a4[t4++]=i;
	}
	printf("1:");
	for (i=0;i<t1;i++)
		printf("%d ",a1[i]);
	printf("\n");
	printf("2:");
	for (i=0;i<t2;i++)
		printf("%d ",a2[i]);
	printf("\n");
	printf("4:");
	for (i=0;i<t3;i++)
		printf("%d ",a3[i]);
	printf("\n");
	printf("8:");
	for (i=0;i<t4;i++)
		printf("%d ",a4[i]);
	printf("\n");
	return 0;
} 
