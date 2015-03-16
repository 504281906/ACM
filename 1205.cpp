#include <stdio.h>
int main()
{
	int n,i,m;
	int a;
	__int64 s,max;
 	scanf("%d",&n);
 	while (n--)
 	{
	 	  scanf("%d",&m);s=0;max=0;
	 	  for (i=0;i<m;i++)
	 	  {
	 	     scanf("%d",&a);
	 	     s+=a;
	 	     if (max<a) max=a;
	      }
	      s-=max;
	      if (s+1>=max) printf("Yes\n");
	      else printf("No\n");
    }
    return 0;
}

