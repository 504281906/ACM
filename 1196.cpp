#include <stdio.h>
int main()
{
 	int i,k,n,s;
 	int a[1000];
   while (scanf("%d",&n) && n!=0)
   {
   		 k=0;
   		 while (n!=0)
   		 {
		  	a[k]=n%2;
			n=n/2; 
			k++;  
   		 }
   for (i=0;i<k;i++)
    if (a[i]==1) {k=i;break;
    }
    s=1;
    for (i=1;i<=k;i++)
     s*=2;
    printf("%d\n",s);
   }  	
}
