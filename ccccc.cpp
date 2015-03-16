#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define maxn 100010
#define eps 1e-15
struct point {
    double x,y;
}p[maxn];
int n;
double mi,mx;
double pika;
double sq(double x){
    return x*x;
}
double tri(double x){
    double ans=0;
    for(int i=0;i<n;i++){
        ans+=sqrt(sq(x-p[i].x)+sq(p[i].y));
    }
    return ans;
}
double slove()
{
	double r=mx,l=mi,lt,rt,ltVal,rtVal;
	int miao=200;
	while(fabs(tri(r)-tri(l))>eps)
	{
	    miao--;
	    if(miao==0) break;
		double mid=(r-l)/3;
		lt=l+mid;
		rt=r-mid;
		ltVal=tri(lt);
		rtVal=tri(rt);
		if(ltVal<rtVal) r=rt;
		else l=lt;
	}
	pika=l;
	return tri(l);
}
int main(){
    int T; scanf("%d",&T);
    int cas=0;
    while(T--){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%lf%lf",&p[i].x,&p[i].y);
            if(i==0){
                mx=p[i].x,mi=p[i].y;
            }
            else{
                mx=max(mx,p[i].x);
                mi=min(mi,p[i].x);
            }
        }
        slove();
        printf("Case %d: %.6lf\n",++cas,pika);
    }
    return 0;
}

