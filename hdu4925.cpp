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
	int T,n,m,i,k;
	LL ans;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&m);
		if (n>m)
		{
			n=n+m;
			m=n-m;
			n=n-m;
		}
		if (m>1)
			k=(m-1)*2;
		else k=1;
		if (n>=2)
			ans=k*2*2+(n-2)*k*4;
		else 
			ans=k;
		cout<<ans<<endl;
	}
	return 0;
}
