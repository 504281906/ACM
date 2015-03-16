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
int main()
{
	int T,i,a[10];
	scanf("%d",&T);
	while (T--)
	{
		for (i=0;i<6;i++)
			scanf("%d",&a[i]);
		sort(a,a+6);
		if (a[5]+a[4]>a[3]+a[2]+a[1])
			puts("Grandpa Shawn is the Winner!");
		else 
			puts("What a sad story!");
	}
	return 0;
}
