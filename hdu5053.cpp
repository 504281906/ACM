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
#include <ctime>
#define LL __int64
#define EPS 1e-8
using namespace std;
int main()
{
	int T;
	scanf("%d",&T);
	int cas=1;
	while (T--)
	{
		LL a,b,i,s=0;
		scanf("%I64d%I64d",&a,&b);
		for (i=a;i<=b;i++)
		{
			s+=i*i*i;
		}
		printf("Case #%d: %I64d\n",cas++,s);
	}
	return 0;
}

