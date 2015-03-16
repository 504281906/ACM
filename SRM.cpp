//Hello. I'm Peter.
#include<cstdio>
#include<iostream>
#include<sstream>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<functional>
#include<cctype>
#include<ctime>
#include<stack>
#include<queue>
#include<vector>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
typedef long double ld;
#define peter cout<<"i am peter"<<endl
#define input freopen("data.txt","r",stdin)
#define INT (0x3f3f3f3f)*2
#define LL (0x3f3f3f3f3f3f3f3f)*2
#define gsize(a) (int)a.size()
#define len(a) (int)strlen(a)
#define slen(s) (int)s.length()
#define pb(a) push_back(a)
#define clr(a) memset(a,0,sizeof(a))
#define clr_minus1(a) memset(a,-1,sizeof(a))
#define clr_INT(a) memset(a,INT,sizeof(a))
#define clr_true(a) memset(a,true,sizeof(a))
#define clr_false(a) memset(a,false,sizeof(a))
#define clr_queue(q) while(!q.empty()) q.pop()
#define clr_stack(s) while(!s.empty()) s.pop()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define dep(i, a, b) for (int i = a; i > b; i--)
#define repin(i, a, b) for (int i = a; i <= b; i++)
#define depin(i, a, b) for (int i = a; i >= b; i--)
#define pi 3.1415926535898
#define eps 1e-6
#define MOD 1000000007
#define MAXN
#define N 110
#define M 1100
struct Edge
{
    int to,next,from;
    int val;
}edge[2*M];
int head[M],w,from;
void add_edge(int from,int to,int val)
{
    w++;
    edge[w].from=from;
    edge[w].to=to;
    edge[w].val=val;
    edge[w].next=head[from];
    head[from]=w;
}
int dp[N][2];
void dfs(int now,int father)
{
    int i,to,val,son=0;
    for(i=head[now];i!=-1;i=edge[i].next)
    {
        to=edge[i].to;
        if(to==father) continue;
        son++;
        dfs(to,now);
    }
    if(!son)
    {
        dp[now][0]=0;
        dp[now][1]=0;
        return;
    }
    int sum;
    //for dp[now][0]
    sum=0;
    for(i=head[now];i!=-1;i=edge[i].next)
    {
        to=edge[i].to;
        if(to==father) continue;
        val=edge[i].val;
        sum+=dp[to][0]+2*val;
    }
    dp[now][0]=sum;
    //for dp[now][1]
    int j,jto,jval,mini=INT;
    for(i=head[now];i!=-1;i=edge[i].next)
    {
        to=edge[i].to;
        if(to==father) continue;
        val=edge[i].val;
        sum=dp[to][1]+val;
        for(j=head[now];j!=-1;j=edge[j].next)
        {
            jto=edge[j].to;
            if(jto==to || jto==father) continue;
            jval=edge[j].val;
            sum+=dp[jto][0]+2*jval;
        }
        mini=min(mini,sum);
    }
    dp[now][1]=mini;
}
class PowerOutage
{
public:
    int estimateTimeOut(vector <int> fromJunction, vector <int> toJunction, vector <int> ductLength)
    {
        int res=0,to,val;
        int len=gsize(fromJunction);
        w=0;
        clr_minus1(head);
        clr(edge);
        rep(i,0,len)
        {
            from=fromJunction[i];
            to=toJunction[i];
            val=ductLength[i];
            add_edge(from,to,val);
            add_edge(to,from,val);
        }
        clr(dp);
        dfs(0,-1);
        res=dp[0][1];
        return res;
    }
};
