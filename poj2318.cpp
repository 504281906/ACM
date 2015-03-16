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
#define eps 1e-8
using namespace std;
int ans[5200];
struct node
{
	int x1,x2;
}f[5200];
int across(int x1,int y1,int x2,int y2)
{
	return x1*y2-x2*y1; 
}
int main()
{
	int i,j,n,m,x1,y1,x2,y2,x,y;
	int ff=1;
	while (~scanf("%d",&n) && n)
	{
		if (ff) ff=0;
		else puts("");
		scanf("%d%d%d%d%d",&m,&x1,&y1,&x2,&y2);
		for (i=0;i<n;i++)
			scanf("%d%d",&f[i].x1,&f[i].x2);
		f[n].x1=x2;f[n].x2=x2;
		memset(ans,0,sizeof(ans));
		for (i=1;i<=m;i++)
		{
			scanf("%d%d",&x,&y);
			for (j=0;j<=n;j++)
			{
				int k=across(f[j].x1-x,y1-y,f[j].x2-x,y2-y);
				if (k<0){
					ans[j]++;
					break;
				}
			}
		}
		for (i=0;i<=n;i++)
			printf("%d: %d\n",i,ans[i]);
	}
	return 0;
}
