#include <stdio.h>
int main()
{
	int n,s,a,i,b,k,f;
 	while (scanf("%d",&n)!=EOF)
 	{
		scanf("%d%d",&a,&b);
	 	s=a+b;f=0;
	 	if (s>0)
		{ 
			k=1;
	 	for (i=1;i<n;i++)
	 	{
			k*=2;
			if (k>s) 
			{
				f=1;
				break;
			} 
		}
		if (f==0 && k*2-1>=s)
			f=1;
		if (f) printf("WaHaHa\n");
		else printf("Yes\n");
	    }
	    else 
	    {
			k=-1;
		for (i=1;i<=n;i++)
	 	{
			k*=2;
			if (s>=k) 
			{
				f=1;
				break;
			} 
		}
		if (f) printf("WaHaHa\n");
		else printf("Yes\n");
		}
	}
return 0;	
}
