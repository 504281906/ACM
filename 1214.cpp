#include <stdio.h>
int main()
{
    int n,i,j;
    while(scanf("%d",&n)!=EOF)
    {
        i=n/2;j=n-i;
        printf("%d\n",i*(i-1)/2+j*(j-1)/2);
    }
    return 0;
}
