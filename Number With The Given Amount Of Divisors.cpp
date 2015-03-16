#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
long long n,ans;
const long long M=1000000000000000009;
int a[11]={2,3,5,7,11,13,17,19,23,29};
void kkk(int x,long long y,int z) //x代表指数，y代表值，z代表第几个素数 
{
	int i;
	if (x>n)
		return ;
	if (x==n && ans>y)
	{
		ans=y;
		return ;
	}
	for (i=1;i<=64;i++)
	{
		if (ans<y*a[z]) break;
		kkk(x*(i+1),y*=a[z],z+1);
	}
}
int main()
{
	while (~scanf("%lld",&n))
	{
		ans=M;
		kkk(1,1,0);
		printf("%lld\n",ans);
	}
	return 0;
}
