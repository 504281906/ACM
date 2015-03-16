#include <stdio.h>
int main()
{
 	int i,j,n,t,m,a[1001];
 	scanf("%d",&n);
 	while (n--)
 	{
	 	  scanf("%d",&m);
	 	  for (i=1;i<=m;i++)
	 	   scanf("%d",&a[i]);
 	      for (i=1;i<m;i++)
 	       for (j=i+1;j<=m;j++)
 	        if (a[i]>a[j])
			  {t=a[i];a[i]=a[j];a[j]=t;}
		  printf("%d",a[1]);
		  for (i=2;i<=m;i++)
		   printf(" %d",a[i]); 
		   printf("\n");
    }
    return 0;
}
