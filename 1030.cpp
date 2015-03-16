#include<stdio.h>
#include<math.h>
#include <stdlib.h>
void find(int n,int &l,int &r,int &level)
{
    int i;
    level=1;
    for(i=1;;i+=2)
    {
        if(n-i<=0)
        {
            l=(n+1)/2;
            r=(i-n)/2+1;
            break;
        }
        level++;
        n-=i;
    }
}

int main()
{
    int m,n;
    int ml,mr,nl,nr,mlevel,nlevel;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        find(m,ml,mr,mlevel);
        find(n,nl,nr,nlevel);
        printf("%d\n",abs(ml-nl)+abs(mr-nr)+abs(mlevel-nlevel));
    }
    return 0;
}
