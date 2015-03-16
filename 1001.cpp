#include<stdio.h>
int main ()
{
    long int n,i,sum;
    while(scanf("%ld",&n)!=EOF)
    { 
     sum=0;
     for(i=1;i<=n;i++)
     {
      sum+=i;
     }
     printf("%ld\n",sum);
     printf("\n");
    }
return 0;
}
