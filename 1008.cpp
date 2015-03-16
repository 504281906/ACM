#include <stdio.h>
int main()
{
 	long i,j,n,t;
 	int a[101];
 	while (scanf("%d",&n)!=EOF && n!=0)
 	{
       a[0]=0;t=n*5;
  	   for (i=1;i<=n;i++)
       	   scanf("%d",&a[i]);
 	   for (i=1;i<=n;i++)
 	    {
	 	   if (a[i]>a[i-1]) 
		 	  t+=(a[i]-a[i-1])*6;
	 	   else 
	 	      t+=(a[i-1]-a[i])*4;
	 	}	  
	 	printf("%d\n",t);
    }
    return 0;
}
