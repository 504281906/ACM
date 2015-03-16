#include <stdio.h>
int num[1000000];
int main()
{
    int n,flag=1,i,j;
    for(i=2;i<1000000;i++)
    {
        if(!num[i])
        {
            for(j=i;j<1000000;j+=i)
              num[j]=flag;
            flag++;
        }
    }
    while(scanf("%d",&n)!=EOF)
    printf("%d\n",num[n]);
    return 0;
}
