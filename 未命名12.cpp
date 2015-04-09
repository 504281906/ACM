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
int a[1100],b[1100],c[1100],d[1100];
int main()
{
	int p,q,l,r,i,j,ans=0;
	scanf("%d%d%d%d",&p,&q,&l,&r);
	for (i=1;i<=p;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
	}
	for (i=1;i<=q;i++)
	{
		scanf("%d%d",&c[i],&d[i]);
	}
	for (i=1;i<=p;i++)
	{
		for (j=1;j<=q;j++)
			if (b[i]-a[i]==d[j]-c[j])
			{
				ans=max(ans,a[i]-c[j]);
			}
	}
	if (ans>=r) printf("%d\n",r-l+1);
	else if (ans>=l) printf("%d\n",ans-l+1);
	else printf("0\n");
	return 0;
}

