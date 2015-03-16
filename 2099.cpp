#include <stdio.h>
int main()
{
	int n,m,i,j,t;
	int a[200][3];
	while (scanf("%d%d",&n,&m) && n+m)
	{
		t=0;
		for (i=0;i<=9;i++)
		 for (j=0;j<=9;j++)
				if ((n*100+i*10+j)%m==0) 
				{
					t++;
					a[t][1]=i;
					a[t][2]=j;
				}
	printf("%d%d",a[1][1],a[1][2]);
    for (i=2;i<=t;i++)
    printf(" %d%d",a[i][1],a[i][2]);
    printf("\n");
	}
	return 0;
}
