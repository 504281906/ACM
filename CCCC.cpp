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
	int n,m,i;
	while (~scanf("%d%d",&n,&m))
	{
		int x=m-n;
		int y=2*n-m;
		if (y<-2 || x<-1) 
		{
			printf("-1\n");
			continue;
		}
		if (x==-1)
		{
			printf("0");
			for (i=1;i<=y-2;i++)
				printf("10");
			printf("\n");
			continue;
		}
		if (y<0)
		{
			for (i=1;i<=x+y;i++)
				printf("110");
			//n-=x+1;
			m=m-2*(x+y);
			for (i=1;i<=m;i++)
				printf("1");
			printf("\n");
			continue;
		}
		for (i=1;i<=x;i++)
			printf("110");
		for (i=1;i<=y;i++)
			printf("10");
		printf("\n");
	}
	return 0;
}
