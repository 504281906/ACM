#include <stdio.h>
int main()
{
	int n,t,i,j,s,k;
	int a[101];
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d",&n,&k);
		for (i=1;i<=n;i++)
		 {
			scanf("%d",&a[i]);
			if (k==i) 
			{
				s=a[i];
				a[i]=0;
		    }
		 }
		 j=0;
		for (i=1;i<=n;i++)
		if (a[i]>s) 
		 j++;
		 printf("%d\n",j);
	}
	return 0;
	
}
