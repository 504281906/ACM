	#include <stdio.h>
	#include <string.h> 
	int main()
	{
		long long a[20010];
		int i,j,n,max,b[20010]; 
		while (~scanf("%d",&n))
		{
			for (i=1;i<=n;i++)
			{
				scanf("%lld",&a[i]);
				if (a[i]>=i)
					b[i]=1;
				else b[i]=0; 
			}
			int max=1;
			for (i=2;i<=n;i++)
			{
				for (j=1;j<i;j++)
					if (a[i]>a[j] && b[i]<b[j]+1 && (a[i]-a[j]>=i-j) && b[i]!=0 && b[j]!=0)	
						b[i]=b[j]+1;
				if (max<b[i]) max=b[i];
			}
			printf("%d\n",max);
		}
		return 0;
	} 
