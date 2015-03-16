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
#define Max(a,b) a>b?a:b
int n,i;
int a[100010];
int b[100010];
int main()
{
	scanf("%d",&n);
	a[0]=0;
	b[n+1]=0x3fffffff;
	for (i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (i=n;i>0;i--)
		if (a[i]<a[i+1]) b[i]=b[i+1];
		else b[i]=i;
	int pos=1;
	int max=0;
	for (i=1;i<=n;i++)
	{
		if (a[i]<=a[i-1]) 
		{
			if (a[i]-1<=a[i-2])
				max=Max(max,b[i]-i+2);
			else max=Max(max,b[i]-pos+1);
			if (a[i-1]+1>=a[i+1]) 
				max=Max(max,i-pos+1);
			else max=Max(max,b[i]-pos+1);
			pos=i;
		}
	}
	if (pos==1) max=n;
	printf("%d\n",max);
	return 0;
}
