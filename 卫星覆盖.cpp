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
#define LL __int64
#define EPS 1e-8
using namespace std;
struct node
{
	int x1,x2;
}f[110][5];
LL ans;
void DFS(int x1,int x2,int y1,int y2,int z1,int z2,int k)
{
	while (k>=0 && (x1>=f[k][1].x2 || x2<=f[k][1].x1
			|| y1>=f[k][2].x2 || y2<=f[k][2].x1
			|| z1>=f[k][3].x2 || z2<=f[k][3].x1))
			k--;
	if (k<0)
	{
		ans+=(x2-x1)*(y2-y1)*(z2-z1);
		return ;
	}
	if (x1<f[k][1].x1)
	{
		DFS(x1,f[k][1].x1,y1,y2,z1,z2,k-1);
		x1=f[k][1].x1;
	}
	if (x2>f[k][1].x2)
	{
		DFS(f[k][1].x2,x2,y1,y2,z1,z2,k-1);
		x2=f[k][1].x2;
	}
	if (y1<f[k][2].x1)
	{
		DFS(x1,x2,y1,f[k][2].x1,z1,z2,k-1);
		y1=f[k][2].x1;
	}
	if (y2>f[k][2].x2)
	{
		DFS(x1,x2,f[k][2].x2,y2,z1,z2,k-1);
		y2=f[k][2].x2;
	}
	if (z1<f[k][3].x1)
	{
		DFS(x1,x2,y1,y2,z1,f[k][3].x1,k-1);
		z1=f[k][3].x1;
	}
	if (z2>f[k][3].x2)
	{
		DFS(x1,x2,y1,y2,f[k][3].x2,z2,k-1);
		z2=f[k][3].x2;
	}
}
int main()
{
	int n;
	while (~scanf("%d",&n))
	{
		int i,x,y,z,r;
		ans=0;
		for (i=0;i<n;i++)
		{
			scanf("%d%d%d%d",&x,&y,&z,&r);
			f[i][1].x1=x-r;f[i][1].x2=x+r;
			f[i][2].x1=y-r;f[i][2].x2=y+r;
			f[i][3].x1=z-r;f[i][3].x2=z+r;
			DFS(f[i][1].x1,f[i][1].x2,f[i][2].x1,f[i][2].x2,f[i][3].x1,f[i][3].x2,i-1);
		}
		cout<<ans<<endl;
	}
	return 0;
}

