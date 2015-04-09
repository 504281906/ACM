#include <stdio.h>
int main()
{
	int n,m,i,x,y,s,j;
	while(~scanf("%d%d",&m,&n))
	{
		int a[50][50]; 
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				scanf("%d",&a[i][j]);
			}
		}	
		int s=0;
		for(i=m-1;i>=0;i--)
		{
			for(j=n-1;j>=0;j--)
			{
				if(a[i][j]>=s||a[i][j]<=-s)
				{
					s=a[i][j];
					x=i;
					y=j;
				}
			}
		}
		printf("%d %d %d\n",x+1,y+1,s);

	}
	return 0;
}

