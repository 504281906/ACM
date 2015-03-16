#include<stdio.h>
int main () 
{
    int i,a;
    __int64 f[51]={0,3,6,6};
    for(i=4;i<=50;i++) 
       f[i] = 2*f[i-2] + f[i-1];
    while (scanf("%d",&a) != EOF) 
    {
        printf("%I64d\n",f[a]);
    }
    return 0;
}
