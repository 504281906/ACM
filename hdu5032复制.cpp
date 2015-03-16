#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define rep(i,n) for (int i=1;i<=n;++i)
typedef long long LL;
#define fi first
#define se second
#define mk make_pair
typedef pair<int,int> pr;
const int N=200005;
pair<int,int> a[N*5],b[N];
int T,Case,A,B,n,m,x,y,w[N],q[N]; LL c[N],ans[N];
bool cmp(const pr &A,const pr &B){return A.se*B.fi<A.fi*B.se;}
bool cmpQ(const int i,const int j){return b[i].se*b[j].fi<b[i].fi*b[j].se;}
bool in(const pr &A,const pr &B){return A.se*B.fi<=A.fi*B.se;}
void add(int x,int v){for (;x<=1000;x+=x&-x) c[x]+=v;}
LL get(int x){LL v=0; for (;x;x-=x&-x) v+=c[x]; return v;}
void ins(const pr &V){add(V.fi,(V.fi+A)*(V.se+B));}
int main()
{
    m=0; rep(i,1000) rep(j,1000) a[++m]=mk(i,j); sort(a+1,a+m+1,cmp);
    scanf("%d",&T);
    while (T--){
        scanf("%d%d%d",&A,&B,&n);
        rep(i,n) scanf("%d%d%d",&x,&y,w+i),b[i]=mk(x,y),q[i]=i;
        sort(q+1,q+n+1,cmpQ); int j=1; rep(i,1000) c[i]=0;
        rep(k,n){
            int i=q[k];
            while (j<=m && in(a[j],b[i])) ins(a[j++]);
            //printf("%d %d %d %d\n",i,w[i],j,get(7));
            ans[i]=get(w[i]);
        }
        printf("Case #%d:\n",++Case);
        rep(i,n) printf("%I64d\n",ans[i]);
    }
    return 0;
}
