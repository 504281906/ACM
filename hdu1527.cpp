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
int f[1000005];
int main()
{
	int i,a,b,k,aa,bb=0;
	for (i=1;bb<=1000000;i++)
	{
		aa=i*((sqrt(5)+1)/2);
		bb=i+aa;
		f[aa]=bb;
		f[bb]=aa;
	}
	while (~scanf("%d%d",&a,&b) && (a+b))
	{
		if (a>b)
		{
			a=a+b;
			b=a-b;
			a=a-b;
		}
		k=b-a;
		int k1=(int)k*((sqrt(5)+1)/2);
		if (k1==a) puts("0");
		else 
		{
			puts("1");
			for (i=a;i>=0;i--)
				if (f[i]==b-a+i)
				{
					printf("%d %d\n",i,f[i]);
					break;
				}
			if (f[a]>a) printf("%d %d\n",a,f[a]);
			else printf("%d %d\n",f[a],a);
		}
	}
	return 0;
}
