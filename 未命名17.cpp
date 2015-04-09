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
int main()
{
	LL x,k,i;
	while (~scanf("%I64d%I64d",&x,&k) && (x+k))
	{
		for (i=2;i<=k;i++)
		{
			if (x % i!=0)
			{
				x=(x/i+1)*i;
			}
			if (i*i>x) break;
		}
		if (k>i)
		{
			x=(x/i)*k;			
		}
		cout<<x<<endl;
	}
	return 0;
}
