#include <stdio.h>
int main()
{
 	__int64 i,s,n;
 	while (scanf("%I64d",&n)!=EOF)
 	{
	 	  s=1;
	 	  for (i=1;i<=n;i++)
	 	   s=s*3;
	 	   printf("%I64d\n",s-1);
     }
     return 0;
}	
