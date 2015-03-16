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
int main()
{
#ifdef DEBUG
	freopen("cin.txt", "r", stdin);
	freopen("cout.txt", "w", stdout);
#endif
	int n,p,k,i;
	while (~scanf("%d%d%d",&n,&p,&k))
	{
	int a=p-k;
	int b=p+k;
	if (a<=1)
	{
		for (i=1;i<p;i++)
			printf("%d ",i);
	}
	else 
	{
		printf("<< ");
		for (i=a;i<p;i++)
			printf("%d ",i);
	}
	printf("(%d)",p);
	if (b>=n)
	{
		for (i=p+1;i<=n;i++)
			printf(" %d",i);
			printf("\n");
	}
	else 
	{
		for (i=p+1;i<=b;i++)
			printf(" %d",i);
		printf(" >>\n");
	}
	}
	return 0;
}
