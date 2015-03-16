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
struct node
{
	int a,b;
}f[100010];
int cmp(node y,node x)
{
		return y.a<x.a;
}
int main()
{
	int n,i;
	scanf("%d",&n);
	int x=0,y=0,f1=0;
	for (i=0;i<n;i++)
	{
		cin>>f[i].a>>f[i].b;
	}
	sort(f,f+n,cmp);
	for (i=1;i<n;i++)
	if (f[i].b<f[i-1].b)
	{
		f1=1;
		break;
	}
	if (f1) puts("Happy Alex");
	else puts("Poor Alex");
	return 0;
}
