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
	int n,i,x;
	scanf("%d",&n);
	int min=10E9+10;
	int max=0;
	int k1=0,k2=0;
	for (i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if (x<min)
		{
		 	min=x;
		 	k1=1;
		}
		if (x>max)
		{
			max=x;
			k2=1;
		}
		if (x==min) k1++;
		if (x==max) k2++;
	}
	printf("%d %d\n",max-min,k1*k2);
	return 0;
}
