#include<stdio.h>
#include<algorithm>
#include<string.h>
long long ans[2001];
long long sum[2001];
int n,T;
int t[2001];
const int mod=1000000007;
inline void Reduce(long long &x){
    if(x>=mod) x-=mod;
    if(x<0) x+=mod;
}
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;++i) scanf("%d",t+i);
        std::sort(t+1,t+n+1);
        memset(sum,0,sizeof(sum));
        memset(ans,0,sizeof(ans));
        ans[0]=1;
        for(int i=1;i<=n;++i){
            sum[0]=ans[0];
            for(int j=1;j<=2000;++j){
                sum[j]=ans[j]+sum[j-1];
                Reduce(sum[j]);
            }
            for(int j=2000;j;--j){
                if(j>t[i]) ans[j]+=sum[j-1]-sum[j-t[i]-1];
                else ans[j]+=sum[j-1];
                Reduce(ans[j]);
            }
        }
        int anspos=0;
        for(int i=1;i<=n;++i) anspos+=t[i];
        printf("%d\n",int(ans[anspos/2]));
    }
    return 0;
}
