#include <stdio.h>
int main()
{
 	int n,j,i;
 	int a[100];
 	while (scanf("%d",&n)!=EOF)
 	{
	 	  i=0;
	 	  while (n!=0)
	 	  {
		   	i++;
			a[i]=n%2;
			n=n/2;
   		  }
   		  for (j=i;j>=1;j--)
   		   printf("%d",a[j]);
    printf("\n");
	 	  
  	}
  	return 0;
}
