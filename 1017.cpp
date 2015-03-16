#include<stdio.h>
int main()
{
	int i,k,n,m,a,b,s,x;
	scanf("%d",&k);
	for(i=0;i<k;i++)
	{
		x=1;
		while(scanf("%d%d",&n,&m),n>0)
		{
			s=0;
			for(a=1;a<n-1;a++)
				for(b=a+1;b<n;b++)
					if((a*a+b*b+m)%(a*b)==0)
						s++;
			printf("Case %d: %d\n",x++,s);
		}
		if(i!=k-1)
			printf("\n");
	}
	return 0;
}
