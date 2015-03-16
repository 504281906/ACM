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
	int n,m,i,a[1010];
	while (~scanf("%d%d",&n,&m))
	{
		int ans=0,t;
		a[0]=-1;
		for (i=1;i<=n;i++)
			scanf("%d",&a[i]);
		if (m==1)
		{
			puts("Alice");
			continue;
		}
		for (i=n;i>0;i-=2)
			ans^=(t=a[i]-a[i-1]-1);
		if (n % 2==1 && m==2)
			ans=ans^(t-1)^t;
		if (ans==0)
			puts("Bob");
		else
			puts("Alice");
	}
	return 0;
}
