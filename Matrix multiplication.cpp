#include <stdio.h>
#define LL __int64
int a[900][900],b[900][900],c[900][900];
int main()
{
    int n,i,j,k;
    while (~scanf("%d",&n))
    {
    	int x;
        for (i=0;i<n;i++)
            for (j=0;j<n;j++)
            {
                scanf("%d",&x);
                a[i][j]=x%3;
            }
        for (i=0;i<n;i++)
            for (j=0;j<n;j++)
            {
                scanf("%d",&x);
                b[j][i]=x%3;
            }
        for (i=0;i<n;i++)
        {
        	for (j=0;j<n;j++)
        	{
        		c[i][j]=0;
           		for (k=0;k<n;k++)
                	c[i][j]=c[i][j]+a[i][k]*b[j][k];
                printf(j==0?"%d":" %d",c[i][j]%3);
            }
            printf("\n");
        }
    }
    return 0;
}
