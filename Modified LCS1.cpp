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
using namespace std;
#define LL __int64
LL x,y,gcd;
void exgcd(LL a ,LL b)
{
	if (!b)
	{
		x=1;
		y=1;
		gcd=a;
		return;
	}
	exgcd(b,a%b);
	LL t=x;
	x=y;
	y=t-a/b*y;
	return ;
}
int main()
{
	int T;
	LL n1,n2,f1,f2,d1,d2;
//	freopen("in.txt", "r", stdin);
//	freopen("outt.txt","w",stdout);
	scanf("%d",&T);
	while (T--)
	{
		cin>>n1>>f1>>d1>>n2>>f2>>d2;
		LL f=f2-f1;
		exgcd(d1,-d2);
		if (f % gcd)
		{
			puts("0");
			continue;
		}
		else
		{
			LL r=abs((-d2)/gcd);
			x=(x*f/gcd % r+r)%r;
			y=(f-x*d1)/(-d2);
			LL dx=abs(d1/gcd);
			LL dy=abs(d2/gcd);
			LL ans=min((n1-x-1)/dy,(n2-y-1)/dx)+1;
			cout<<ans<<endl;
		}
	} 
	return 0;
}
