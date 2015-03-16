#include <stdio.h>
int main()
{
 	int a,n,s,j,i,m;
 	scanf("%d",&n);
 	for (i=1;i<=n;i++)
 	{
	 	scanf("%d",&m);s=0;
	 	for (j=1;j<=m;j++)
	 	 {
		    scanf("%d",&a);
		    s+=a;
		  }
	    if (i==n) printf("%d\n",s);
	    else printf("%d\n\n",s);
    }
    return 0;
}
