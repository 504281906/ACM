#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;
#define rep(i,n) for(i=1;i<=(n);++i)
#define rep2(i,x,y) for(i=(x);i<=(y);++i)
#define lnk iterator
#define pb push_back
#define mp make_pair
#define inf 100000000
typedef vector<int> VI;
typedef vector< pair<int,int> > VII;
typedef long long LL ;
struct mylnk{int t,next;} st[100010];
int f[100010],next[100010],last[100010],a[100010];
pair<int,int> b[100010];
int main()
{
    int i,n,head,top;
    while (scanf("%d",&n)!=EOF)
    {
        rep(i,n) scanf("%d",&a[i]);
        rep(i,n) b[i]=mp(a[i],i);
        sort(b+1,b+n+1);
        int t=0; b[0]=mp(b[1].first-1,0);
        rep(i,n)
        {
            if (b[i].first!=b[i-1].first) t++;
            a[b[i].second]=t;
        }
        rep(i,n) last[i]=n+1;
        for (int i=n;i>=1;--i) {next[i]=last[a[i]];last[a[i]]=i;}
        head=1;
        top=1;
        st[1].t=0;
        st[1].next=0;
        f[0]=0;
        next[0]=n+1;
        rep(i,n)
        {
            int p=head;
            f[i]=inf;
            int cnt=0;
            int q=0;
            while (p!=0)
            {
                if (next[st[p].t]<=i)
                    if (q!=0)
                    {
                        st[q].next=st[p].next;
                        p=st[p].next;
                        continue;
                    }
                    else
                    {
                        q=head=st[p].next;
                        p=st[p].next;
                        continue;
                    }
                ++cnt;
                if (cnt*cnt>=f[i]) break;
                f[i]=min(f[i],f[st[p].t]+cnt*cnt);
                q=p; p=st[p].next;
            }
            top++;
            st[top].t=i;
            st[top].next=head;
            head=top;
        }
        printf("%d\n",f[n]);
        //rep(i,n) printf("%d ",f[i]); printf("\n");
    }
    return 0;
}
