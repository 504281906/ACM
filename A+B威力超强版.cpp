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
#define LL __int64
#define EPS 1e-8
using namespace std;
LL x,y,g;
LL gg(LL a,LL b)
{
	if (b==0) return a;
	else return gg(b,a%b);
}
void exgcd(LL a,LL b)
{
	if (!b)
	{
		x=1;
		y=0;
		g=a;
		return ;
	}
	exgcd(b,a % b);
	LL t=x;
	x=y;
	y=t-a/b*y;
}
int main()
{
	LL a,b,c;
	scanf("%I64d%I64d%I64d",&a,&b,&c);
	if (a>b)
	{
		LL t=a;
		a=b;
		b=t;
	}
	if (c==a || c==b)
	{
		puts("YES");
		return 0;
	}
	if (a==0)
		if (b==0) 
			puts("NO");
		else if (c % b==0) puts("YES");
			else puts("NO");
	else
	{
		exgcd(a,b);
		if (c % g) 
		{
			puts("NO");
			return 0;
		}
		a/=g;b/=g;c/=g;
		x=ceil((-x)*1.0/b);
		y=(c-x*a)/b;
		if (x==0)
		{
			x+=b;
			y-=a;
		}
		bool flag=0;
		while (y>0)
		{
			if (gg(x,y)==1)
			{
				flag=1;
				break;
			}
			x+=a;
			y-=b;
		}
		if (flag) puts("YES");
		else puts("NO");
	}
	return 0;
}

