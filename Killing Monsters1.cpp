#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100005
#define LL long long 
LL a[100005];
int main()
{
        int n;
        while(scanf("%d",&n) != EOF,n)
        {
            memset(a,0,sizeof(a));
            int tsum ;
            scanf("%d",&tsum);
            for(int i =1 ;i<=tsum ;i ++)
            {
               int ta,tb,tc;
               scanf("%d %d %d",&ta,&tb,&tc);
               a[ta] += tc;
               a[tb+1] -= tc;
            }
            LL sum = 0 ;
            LL ta = 0 ; 
            for(int i = 1;i <= n;i ++)
            {
               ta += a[i];
               sum += ta;
               a[i] = sum;
               //printf("%I64d ",a[i]);
            }
            //printf("\n");
            scanf("%d",&tsum);
            int ans = 0 ; 
            for(int i = 1;i <= tsum ;i ++)
            {
                LL ta,tb;
                scanf("%I64d %I64d",&ta,&tb);
                if(a[n] - a[tb-1] < ta)
                {
                	ans ++ ;
                }
            }
            printf("%d\n",ans);
        }
    return 0 ;
}
