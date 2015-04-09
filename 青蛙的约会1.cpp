#include <iostream>
#include <cstring>
using namespace std;
#define LL long long
LL x,y,gcd;
void exgcd(LL a,LL b)
{
	if (b==0)
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
	return;
}
int main()
{
	LL x1,y1,m,n,l;
	while (cin>>x1>>y1>>m>>n>>l)
	{
		LL a=n-m;
		LL b=x1-y1;
		exgcd(l,a);
		LL r=l/gcd;
		if (b % gcd) cout<<"Impossible"<<endl;
		else 
		cout<<(y*b/gcd % r+r) % r<<endl;
	}
	return 0;
}
