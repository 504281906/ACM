#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
	int x=23,y=28,z=33;
	int a,b,c,d;
	long long k=x*y*z;
	int T=1;
	while (~scanf("%d%d%d%d",&a,&b,&c,&d) && (a!=-1))
	{
		long long a1=5544,b1=14421,c1=1288;
		a1=a1*a;
		b1=b1*b;
		c1=c1*c;
		long long s=(a1+b1+c1-d+k) % k;
		if (s==0) s=k;
		printf("Case %d: the next triple peak occurs in %lld days.\n",T++,s);
	} 
	return 0;
}
