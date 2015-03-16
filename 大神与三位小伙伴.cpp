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
bool pd(int a,int b,int c)
{
	if ( (a==b && a!=c) || (a==c && a!=b) || (b==c && a!=b))
		return true;
	return false;
}
int T,cas;
long long i,j,k,ans,n;
#define d 1000000007
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout); 
	scanf("%d",&T);
	for (cas=1;cas<=T;cas++)
	{
		scanf("%lld",&n);
		ans=0;
		for (i=1;i<=n;i++)
			for (j=1;j<=n;j++)
				for (k=1;k<=n;k++)
					if (!pd(i,j,k))
					{
						ans=(ans+((n-i+1)%d)*((n-j+1)%d)*((n-k+1)%d)%d)%d;
					}
		printf("Case %d: %lld\n",cas,ans);
	}
	return 0;
}
