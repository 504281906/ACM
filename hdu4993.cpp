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
	int T,a,b,c,q,w,ans;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d%d",&a,&b,&c);
		q=max(a,b);w=min(a,b);
		ans=0;
		while (c>0)
		{
			c-=q;
			if (c % w==0 && c / w >=1)
				ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
