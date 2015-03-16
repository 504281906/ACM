#include "iostream"
#include "algorithm"
#include "cstdio"
#include "cstring"
#include "set"
#include "vector"
#include "queue"
#include "map"
#include "cmath"
#include "ctime"
#include "stack"

using namespace std;
typedef long long LL;
const int MOD = 1000000007;
const int MAXN = 100000+10;
const double PI = acos((double)-1);
typedef pair< int , int >  PII;

struct arrow{
    double l;
    double r;
    int pos;
    double x;
    bool operator<(arrow a)const{
        return x<a.x;
    }
    arrow(){}
    arrow(double X){
        x = X;
    }
}dp[MAXN];

struct node{
    double x,y;
    bool operator<(node a)const{
        return y>a.y;
    }
}Build[MAXN];

void Rupdata(int l,int r,int p){
    double row;
    for(;l<r;l++){
        row = Build[p].y/(dp[l].x-Build[p].x);
        if(row<=dp[l].r)return;
        dp[l].r = row;
    }
}
void Lupdata(int l,int r,int p){
    double row;
    for(;r>=l;r--){
        row = Build[p].y/(Build[p].x-dp[r].x);
        if(row<=dp[r].l)return;
        dp[r].l = row;
    }
}
double ans[MAXN];
int main()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        int N,Q;
        scanf("%d",&N);
        for(int i = 0;i<N;i++)scanf("%lf%lf",&Build[i].x,&Build[i].y);
        sort(Build,Build+N);
        scanf("%d",&Q);
        for(int i=0;i<Q;i++){
            scanf("%lf",&dp[i].x);
            dp[i].pos=i;
            dp[i].l=0;
            dp[i].r=0;
        }sort(dp,dp+Q);
        for(int i=0;i<N;i++){
            int pos = lower_bound(dp,dp+Q,arrow(Build[i].x))-dp;
            Rupdata(pos,Q,i);
            Lupdata(0,pos-1,i);
        }
        for(int i=0;i<Q;i++){
            //cout<<dp[i].l<<endl;
            ans[dp[i].pos] = (PI - atan(dp[i].l)-atan(dp[i].r))*180.0/PI;
        }
        printf("Case #%d:\n",t);
        for(int i=0;i<Q;i++)
            printf("%.10lf\n",ans[i]);
    }
    return 0;
}
