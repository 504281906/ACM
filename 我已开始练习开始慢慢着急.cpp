#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
#include <map>
#include <stack>
#include <list>
#include <vector>
#include <ctime>
#define LL __int64
#define EPS 1e-8
#define Pi acos(-1)
using namespace std;
struct node
{
	double x,h;
	bool operator <(node a)const
	{
		return h>a.h;
	}
}a[100010];
struct node1
{
	double x,ma,mb;
	int pos;
	bool operator <(node1 a)const
	{
		return x<a.x;
	}
	node1 (){}
	node1 (double X)
	{
		x=X;
	}
}b[100010];
double ans[100010];
void Rupdata(int l,int r,int p){
    double row;
    for(;l<r;l++){
        row =a[p].h/(b[l].x-a[p].x);
        if(row<=b[l].ma)return;
        b[l].ma = row;
    }
}
void Lupdata(int l,int r,int p){
    double row;
    for(;r>=l;r--){
        row = a[p].h/(a[p].x-b[r].x);
        if(row<=b[r].mb)return;
        b[r].mb = row;
    }
}
int main()
{
	int T,i,j,n,q;
	scanf("%d",&T);
	int cas=1;
	while (T--)
	{
		scanf("%d",&n);
		for (i=0;i<n;i++)
			scanf("%lf%lf",&a[i].x,&a[i].h);
		sort(a,a+n);
		scanf("%d",&q);
		for (i=0;i<q;i++)
		{
			scanf("%lf",&b[i].x);
			b[i].ma=0,b[i].mb=0;
			b[i].pos=i;
		}
		sort(b,b+q);
		for (i=0;i<n;i++)
		{
			double d;
			int pos;
			pos=lower_bound(b,b+q,node1(a[i].x))-b;
			/*for (j=pos-1;j>=0;j--)
			{
				double kk=a[i].h/(a[i].x-b[j].x);
				if (b[j].mb<kk)
					b[j].mb=kk;
				else break;
			}
			for (j=pos;j<q;j++)
			{
				double kk=a[i].h/(b[j].x-a[i].x);
				if (b[j].ma<kk)
					b[j].ma=kk;
				else break;
			}*/
			Rupdata(pos,q,i);
            Lupdata(0,pos-1,i);
		}
		printf("Case #%d:\n",cas++);
		/*for(i=0;i<q;i++){
            //cout<<dp[i].l<<endl;
            ans[b[i].pos] = (Pi - atan(b[i].ma)-atan(b[i].mb))*180.0/Pi;
        }
        for(i=0;i<q;i++)
            printf("%.10lf\n",ans[i]);*/
		for (i=0;i<q;i++)
			printf("%.10lf\n",(Pi-(atan(b[b[i].pos].ma)-atan(b[b[i].pos].mb)))*180.0/Pi);
	}
	return 0;
}
