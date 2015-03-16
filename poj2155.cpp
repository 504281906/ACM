#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
void update(int x,int y,int x1,int y1)
{
	sum(x,y);
	sum(x1+1,y);
	sum(x,y1+1);
	sum(x1+1,y1+1);
}
void sum(int x,int y)
{
	while (x<n)
	{
		int y1=y;
		while (y1<n)
		{
			a[x][y1]^=1;
			y1+=(y1 & -y1);
		}
		x+=(x & -x);
	}
}
void answer(int x,int y)
{
	while (x>0)
	{
		int y1=y;
		while (y1>0)
		{
			ans= (ans+a[x][y1])&1;
			y1-=(y1 & -y1);
		}
		x-=(x & -x);
	}
	ans&=1;
	printf("%d\n",ans);
}
int main()
{
	int T,n,m;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&m);
		int *a[n+2]= new int[n+2];
		memset(a,0,sizeof(a)); 
		while (m--)
		{
			char c[2];
			scanf("%s",&c);
			if (c[0]=='C')
			{
				int x,x1,y,y1;
				scanf("%d%d%d%d",&x,&y,&x1,&y1);
				getchar();
				update(x,y,x1,y1);
			}
			else 
			{
				int x,y;
				scanf("%d%d",&x,&y);
				getchar();
				answer(x,y);
			}
		}
	}
	return 0;
}

