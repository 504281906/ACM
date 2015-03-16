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
int d[1010];
int main()
{
#ifdef DEBUG
	freopen("cin.txt", "r", stdin);
	freopen("cout.txt", "w", stdout);
#endif
	int n,m;
	scanf("%d%d",&n,&m);
	memset(d,0,sizeof(d));
	int i,j,f=0;
	getchar();
	for (i=1;i<=n;i++)
	{
		int a=0,b=0;
		for (j=1;j<=m;j++)
		{
			char c;
			scanf("%c",&c);
			if (c=='G') a=j;
			if (c=='S')
			{
				if (a==0) 
				{
					f=1;
					break;
				}
				else 
					d[j-a]=1;
			}
		}
		getchar();
		if (f) break;
	}
	int k=0;
	if (f) printf("-1\n");
	else
	{
		for (i=1;i<=1000;i++)
			if (d[i]) k++;
		printf("%d\n",k);
	}
	return 0;
}
