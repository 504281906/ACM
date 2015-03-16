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
int a,b,x,y,z;
int gcd(int a,int b)
{
	if (b==0)
	{
		x=1;
		y=0;
		z=a;
		return 0;
	}
	else
	{
		gcd(b,a%b);
		int t=x;
		x=y;
		y=t-a/b*y;
	}
	return 0;
}
int main()
{
	while (~scanf("%d%d",&a,&b))
	{
		if (a<b)
		{
			a=a+b;
			b=a-b;
			a=a-b;
		}
		gcd(a,b);
		printf("%d = %d*%d + %d*%d\n",z,x,a,y,b);
	}
	return 0;
}
