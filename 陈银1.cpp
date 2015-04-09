#include<stdio.h>
#include<math.h>
int main()
{
	int i,g,n,m,j=1;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n<m)
			g=n;
		else
			g=m;
		for(i=g;i>1;i--)
			if(n%i==0&&m%i==0)
			{
			  j=j*i;
			  n=n/i;
			  m=m/i;
            }
			j=j*n*m;
			printf("%d\n",j);
    }
	return 0;
}
