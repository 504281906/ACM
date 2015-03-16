#include<vector>
#include<list>
#include<map>
#include<set>
#include<deque>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<ctime>
#define LL __int64
using namespace std;
#define M 1000000007
LL dpy[1002][2100];
LL dpx[1002][2100];
int a[1002];

int main(){
    int t; 
    scanf("%d",&t);
    while(t--)
    {
        int n; 
        scanf("%d",&n);
        memset(dpy,0,sizeof(dpy));
        memset(dpx,0,sizeof(dpx));
        int temp ; 
        for(int i = 1;i <= n;i ++)
        {
            scanf("%d",&a[i]);
            dpy[i][a[i]] = 1; 
            for(int j = 0;j <= 2048;j ++)
            { 
                if(dpy[i-1][j])
                {
                    dpy[i][j] =(dpy[i][j]+dpy[i-1][j])%M;
                    dpy[i][j^a[i]] = (dpy[i][j^a[i]]+dpy[i-1][j]) % M; 
                }
            }
        }
    /*    for(int i = 0 ;i <= n;i ++)
        {
           for(int j = 0 ;j <= 10;j ++)
               printf("%I64d ",dpy[i][j]);
           printf("\n");
        }
        printf("\n");*/
        LL ans = 0 ; 
        for(int i = n;  i >= 2 ;i -- )
        {
            dpx[n][a[i]] = 1 ; 
            ans = (ans+dpy[i-1][a[i]])% M;
            int tsum[2050];
            memset(tsum,0,sizeof(tsum));
            for(int j = 0 ;j <= 2048;j ++)
            {
                if(dpx[i+1][j])
                {
                    ans = (ans + dpy[i-1][j&a[i]]*dpx[i+1][j])%M;
                   // printf("%I64d %d %d\n",ans,i,j);
                    tsum[j&a[i]] = (tsum[j&a[i]] + dpx[i+1][j]) % M;
                }
            }
            for(int j = 0;j <= 2048 ;j ++)
                dpx[i][j] = (dpx[i][j] + dpx[i+1][j] + tsum[j])%M;
        }
        printf("%I64d\n",ans%M); 
    }
    return 0;
}
