
#include<iostream>
#include <cmath>
#include <cstdio>
using namespace std;
#define LL long long 
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
LL f(LL x)
{
   if(x < 0)
	   return -x; 
   else return x;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		LL d1,d2,n1,n2,f1,f2;
		cin>>n1>>f1>>d1>>n2>>f2>>d2;
		int ok =1;  
		if (d1<=d2 && f1>f2)
		{
			ok=0;
			d1+=d2;
			d2=d1-d2;
			d1=d1-d2;
		}
		exgcd(d1,d2);
		if (ok==0)
		{
			LL tt=x;
			x=y;
			y=tt;
		}
	//	printf("%lld %lld\n",x,y);
		LL aa = (f2-f1);
        x = f(x*aa);
    	y = f(y*aa);
		LL t1 = abs(d2/q);
		LL t2 = abs(d1/q);
	//	printf("%lld %lld %lld %lld\n",x,y,t1,t2);
		LL ans = 0;
		if(x < n1 && y < n2)
		  ans = min((n1-(x+1))/t1+1,(n2-(y+1))/t2+1);	
		if (ans < 0 ) printf("0\n");
		else  printf("%lld\n",ans);
	}
	return 0;
}
