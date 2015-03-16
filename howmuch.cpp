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
	int T,i,n;
	LL ans,q,p;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%I64d",&ans);
		scanf("%d",&n);
		for (i=1;i<=n;i++)
		{
			scanf("%I64d %I64d",&q,&p);
			ans=ans+q*p;
		}
		cout<<ans<<endl;
	}
	return 0;
}

