#include <stdio.h>
long long a,b,n,m;
void FF()
{
	long long t,x=a,y=1,x1=1,y1=0;
	while (n!=0)
	{
		if (n&1)
		{
			t=x1;
			x1=(x*x1+y*y1*b)%m;
			y1=(t*y+y1*x)%m;
		}
		t=x;
		x=(x*x+y*y*b)%m;
		y=(2*t*y)%m;
		n>>=1;
	}
	printf("%lld\n",2*x1%m);
} 
int main()
{
	while (~scanf("%lld%lld%lld%lld",&a,&b,&n,&m))
		FF();
	return 0;
}	
