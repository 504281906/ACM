#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;

/*    Œ‚…Ò√¿»Áª≠    O(°…_°…)O~    */
int q[200055];
int main()
{
    int T;
    scanf("%d",&T);
    int t=T;
    while (T--){
        int n,m,l;
        scanf("%d%d%d",&n,&m,&l);
       // s.clear();
        for (int j=1;j<=n;j++){
            int g;
            scanf("%d",&g);
            q[j]=g;
        }
        q[n+1]=m;q[0]=0;
        sort(q,q+n+2);
        int now=0;
        int pos=0,last=0,key=0;
        int ans=0;
        while (now<m){
            while (pos<=n+1 && q[pos]-now<=l) pos++;
            pos--;
            if (q[pos]!=now){
                key=l-(q[pos]-now);
                now=q[pos];
                ans++;
            }else{
                int len=q[pos+1]-now-(l+1);
                ans+=len/(l+1)*2;
                now=now+len/(l+1)*(l+1);
                len+=l+1;
                now+=key+1;
                ans++;
                key=(l-(key+1));
                if (q[pos+1]-now<=l) continue;
                now+=key+1;
                ans++;
                key=(l-key-1);
                if (q[pos+1]-now<=l) continue;
                now+=key+1;
                ans++;
                key=(l-key-1);
                if (q[pos+1]-now<=l) continue;
            }
        }
        printf("Case #%d: %d\n",t-T,ans);
    }
    return 0;
}

