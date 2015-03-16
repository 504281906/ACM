#include <stdio.h>
int main()
{
 	int n,i,j,y;
 	char x;
 	scanf("%d\n",&n);
 	for (i=1;i<=n;i++)
	 {
      	scanf("%s%d",&x,&y);
      	if(x>='a'&&x<='z')printf("%d\n",96-x+y);
        else printf("%d\n",x-64+y);
     }
     return 0;
}

