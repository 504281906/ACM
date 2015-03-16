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
#define LL long long

using namespace std;
int hs[100005];
int hs1[100006];
int ans[100005][2];
int a[100005];
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output1","w",stdout);
    int n ; 
    while(scanf("%d",&n) != EOF,n)
    {

        memset(hs,0,sizeof(hs));
        memset(ans,0,sizeof(ans));
        memset(hs1,0,sizeof(hs1));
        for(int i = 1;i <= n;i ++)
        {
            scanf("%d",&a[i]);
            int p = sqrt(a[i]+1e-8);
            for(int j = 1;j <= p ;j++)
            {
                if(a[i] % j == 0 )
                {
                	if(!ans[hs[j]][1])
                		ans[hs[j]][1] = a[i];
                	if(!ans[hs[a[i]/j]][1])
                		ans[hs[a[i]/j]][1] = a[i];
                }
            }
            hs[a[i]] = i;
        }
        for(int i = n;i >= 1;i--)
        {
            int p = sqrt(a[i]+1e-8);
            for(int j = 1;j <= p ;j ++)
            {
                if(a[i]%j == 0 )
                {
                   if(!ans[hs1[j]][0])
                        ans[hs1[j]][0] = a[i];
                   if(!ans[hs1[a[i]/j]][0])
                       ans[hs1[a[i]/j]][0] = a[i];
                }
            }
            hs1[a[i]] = i ; 
        }
        LL sum = 0 ; 
        for(int i = 1;i <= n;i ++)
        {
            for(int j = 0 ;j <= 1;j ++)
                if(!ans[i][j])
                    ans[i][j] = a[i];
            //printf("%d %d\n",ans[i][0],ans[i][1]);
            sum += 1ll*ans[i][0] * ans[i][1];
        }
        printf("%I64d\n",sum);
    }
    return 0;
}
