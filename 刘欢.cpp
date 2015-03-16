#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
struct node
{
	int x,y;
}a[5];
int f[100][100];
int main()
{
	int n,i,j;
	a[0].x=1;a[0].y=0;
	a[1].x=0;a[1].y=1;
	a[2].x=-1;a[2].y=0;
	a[3].x=0;a[3].y=-1;
	while (~scanf("%d",&n))
	{
		memset(f,0,sizeof(f));
		int x=1,y=1,t=0;
		for (i=1;i<=n*n;i++)
		{
			f[x][y]=i;
			int x1=x+a[t].x;
			int y1=y+a[t].y;
			if (x1>n || x1==0 || y1>n || f[x1][y1]) t=(t+1)%4;
			x+=a[t].x;
			y+=a[t].y;
		}
		for (i=1;i<=n;i++)
		{
			for (j=1;j<=n;j++)
			printf("%4d",f[i][j]);
			printf("\n");
		}
	}
	return 0;
}

