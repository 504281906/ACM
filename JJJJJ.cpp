#include<iostream>
#include <cmath>
using namespace std;
#define LL __int64
LL x,y,q;
void exgcd(LL a,LL b)
{
    if (b==0)
    {    
		x=1;
		y=0;
		q=a;
	}
    else
    {
        exgcd(b,a%b);
        LL t=x;
        x=y; 
		y=t-a/b*y;
    }
}
int main()
{
	int T;
    LL d1,d2,n1,n2,f1,f2;
    scanf("%d",&T);
    while (T--)
    {
    cin>>n1>>f1>>d1>>n2>>f2>>d2;
    //if (d1<d2) swap(d1,d2);
    exgcd(d1,d2);
    cout<<x<<" "<<y<<endl; 
    LL f=f2-f1;
    x*=f;
    y*=f;
    LL f3=f1+(d1*(n1-1));
    LL f4=f2+(d2*(n2-1));
    LL ff1=max(f1,f2);  //ff1左边界 
    LL ff2=min(f3,f4);  //ff2右边界 
    LL s1=ff1+fabs(x)*d1;  //第一个点 
    LL p=d1*d2/q;  //p是最小公倍数
	s1=s1-((s1/p+1)*p); 
    LL ans1=(ff1-1-s1)/p;
    LL ans2=(ff2-s1)/p;
    if (ff1>ff2) printf("0\n");
    else
    printf("%I64d\n",ans2-ans1);
	}
return 0;
}
