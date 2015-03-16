#include<stdio.h>
int main()
{
    int i;
    __int64 l[42]={0,3,8};
    int n;
    for(i=3;i<42;i++)
        l[i]=2*(l[i-1]+l[i-2]);
    while(scanf("%d",&n)!=EOF)
        printf("%I64d\n",l[n]);
    return 0;
}

