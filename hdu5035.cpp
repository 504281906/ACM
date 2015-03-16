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
	int T,i,n;
	scanf("%d",&T);
	for (int c=1;c<=T;c++)
	{
		scanf("%d",&n);
		double s=0;
		for (i=1;i<=n;i++)
		{
			double k;
			scanf("%lf",&k);
			s+=k;
		}
		for (i=1;i<=n;i++)
		{
			int k;
			scanf("%d",&k);
		}
		printf("Case #%d: %lf\n",c,(n+1)*1.0/s);
	}
	return 0;
}

