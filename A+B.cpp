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
__int64 x,y;
unsigned __int64 gcd;
LL gcd1(LL a,LL b)
{
	if (b==0) return a;
	else return gcd1(b,a%b);
}
void exgcd(unsigned __int64 a,unsigned __int64 b)
{
	if (!b)
	{
		x=1;
		y=0;
		gcd=a;
		return;
	}
	exgcd(b,a % b);
	unsigned __int64 t=x;
	x=y;
	y=t-a/b*y;
}
int main()
{
	unsigned __int64 n,m,k;
	scanf("%I64d%I64d%I64d",&n,&m,&k);
	if (n>m)
	{
		n+=m;
		m=n-m;
		n=n-m;
	}
	if (n==k || m==k) {puts("YES");return 0;}
	if (n==0 && m==0)
	{
		if (k!=0)
			puts("NO");
		else puts("YES");
		return 0;
	}
	exgcd(n,m);
	if (k % gcd!=0)
		puts("NO");
	else
	{
		//t(min)=(t/gcd(l,a)*b % r+r)%r.kmin=(b-a(min)*t)/L;
		x*=k/gcd;
		y*=k/gcd;
		unsigned __int64 a=m/gcd;
		unsigned __int64 b=n/gcd;
		if (x==0)
		{
			x+=a;
			y-=b;
		}
		int flag=0;
		while (y>0)
		{
			if (gcd1(x,y)==1)
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
