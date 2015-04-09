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
	int a[110];
	int n,p,i,q,k,flag=0;
	memset(a,0,sizeof(a));
	scanf("%d",&n);
	scanf("%d",&p);
	for (i=1;i<=p;i++)
	{
		scanf("%d",&k);
		a[k]=1;
	}
	scanf("%d",&q);
	for (i=1;i<=q;i++)
	{
		scanf("%d",&k);
		a[k]=1;
	}
	for (i=1;i<=n;i++)
		if (a[i]==0)
		{
			flag=1;
			printf("Oh, my keyboard!");
			break;
		}
	if (flag==0) printf("I become the guy.");
	return 0;
}

