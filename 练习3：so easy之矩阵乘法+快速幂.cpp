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
long long a,b,n,m;
void ksm(int n)
{
	long long t,x=1,y=0,x1=a,y1=1;
	while (n!=0)
	{
		if (n % 2==1)
		{
			t=x;
			x=(x*x1+y*y1*b)%m;
			y=(t*y1+y*x1)%m;
		}
		t=x1;
		x1=(x1*x1+y1*y1*b)%m;
		y1=(2*t*y1)%m;
		n=n>>1;
	}
	printf("%lld\n",2*x%m);
}
int main()
{
	while(~scanf("%lld%lld%lld%lld",&a,&b,&n,&m))
		ksm(n);
	return 0;
}
