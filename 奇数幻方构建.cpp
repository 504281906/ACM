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
int a[1000][1000];
int n,i,j;
int main()
{
	while (~scanf("%d",&n) && n)
	{
		if (n % 2==0) 
		{
			printf("«Î ‰»Î∆Ê ˝,ok?\n");
			continue;
		}
		memset(a,0,sizeof(a));
		a[1][n/2+1]=1;
		int s=2;
		int x=1,y=n/2+1;
		while (s<=n*n)
		{
			x-=1;
			y+=1;
			if (x==0 && y==n+1)
			{
				x=2;y=n;
			}
			else if (x==0) x=n;
			else if (y==n+1) y=1;
			if (a[x][y])
			{
				x+=2;
				y-=1;
			}
			a[x][y]=s++;
		}
		int ans=0;
		for (i=1;i<=n;i++)
		{
			for (j=1;j<=n;j++)
				printf("%4d",a[i][j]);
			printf("\n");
			ans+=a[i][j-1];
		}
		cout<<ans<<endl;
	}
	return 0;
}
