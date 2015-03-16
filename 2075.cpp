#include<stdio.h>
main()
{
    int t,a,b;
    scanf("%d",&t);
    while(t--)
    {
       scanf("%d%d",&a,&b);
       if(a%b==0)
       printf("YES\n");
       else printf("NO\n");
    }
}
