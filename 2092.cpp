#include <stdio.h>
int main()
{
 	int i,t,n,m;
 	while (scanf("%d%d",&n,&m)!=EOF || n!=0 &&m!=0)
 	{
	 	  t=0;
	 	  for (i=-10000;i<=10000;i++)
	 	   if (i*(n-i)==m)
	 	    {
  			  t=1;
			  break;
            }
     if (t) printf("Yes\n");
     else printf("No\n");
    }
return 0;
}

