#include <stdio.h>
int gcd(int a,int b)
{
    return a%b==0?b:gcd(b,a%b);
}
int main()
{
    int i,s,n,a[101];
    int gad(int a,int b);
   while (scanf("%d",&n)!=EOF)
   {
         s=1;
        for (i=1;i<=n;i++)
         {
           scanf("%d",&a[i]); 
           s=s*a[i];
         }
        for (i=2;i<n;i++)
          a[1]=gad(a[1],a[i]);
        printf("%d",s/a[1]);
   }
 return 0;
}
