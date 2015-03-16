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
//#define DEBUG
int a[3010],s[3000*3000/2],i,j,n,m;
int cmp(int a,int b)
{
	return a>b;
}
int main()
{
#ifdef DEBUG
	freopen("cin.txt", "r", stdin);
	freopen("cout.txt", "w", stdout);
#endif
	while(~scanf("%d%d",&n,&m))
	{
	for (i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int t=0;
	for (i=1;i<n;i++)
		for (j=i+1;j<=n;j++)
		s[t++]=a[i]+a[j];
	sort(s,s+t,cmp);
	for (i=0;i<m;i++)
	{
		if (i==0) printf("%d",s[i]);
		else printf(" %d",s[i]);
	}
	printf("\n");
	}
	return 0;
}
