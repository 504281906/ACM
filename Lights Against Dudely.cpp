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
char mp[210][210];
int f[20];
int fx[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
struct node
{
	int x,y;
}p[20];
int main()
{
	int n,m,i,j,l;
	while (~scanf("%d%d",&n,&m) && (n+m))
	{
		int k=0;
		memset(mp,'*',sizeof(mp)); 
		for (i=1;i<=n;i++)
		{
			getchar();
			for (j=1;j<=m;j++)
			{
				scanf("%c",&mp[i][j]);
				if (mp[i][j]=='.')
				{
					p[k].x=i;
					p[k].y=j;
					k++;	
				}
			}
		}
		if (k==0)
		{
			printf("0\n");
			continue;
		}
		int min=20;
		for (i=1;i<1<<k;i++)
		{
			int t=0;
			for (j=0;j<k;j++)
			{
				f[j]=0;
				if (i & (1<<j))
				{
					f[j]=1;
					t++;		
				}
			}
			for (j=0;j<k;j++)
			{
				int lig=0;
				if (f[j]==0) continue;
				for (int h=0;h<k;h++)
					mp[p[h].x][p[h].y]='.';
				for (l=0;l<k;l++)
				{
					if (l==j || f[l]==0) continue;
					if (mp[p[l].x-1][p[l].y]=='#' || mp[p[l].x][p[l].y+1]=='#') continue;
					if (mp[p[l].x][p[l].y]=='.')
					{
						mp[p[l].x][p[l].y]='*';
						lig++;
					}
					if (mp[p[l].x-1][p[l].y]=='.')
					{
						mp[p[l].x-1][p[l].y]='*';
						lig++;
					}
					if (mp[p[l].x][p[l].y+1]=='.')
					{
						mp[p[l].x][p[l].y+1]='*';
						lig++;
					}
				}
				for (l=0;l<4;l++)
				{
					int ll=lig;
					int a=l;
					int b=(l+1)%4;
					if (mp[p[j].x+fx[a][0]][p[j].y+fx[a][1]]=='#' || mp[p[j].x+fx[b][0]][p[j].y+fx[b][1]]=='#')
						continue;
					if (mp[p[j].x][p[j].y]=='.')
						ll++;
					if (mp[p[j].x+fx[a][0]][p[j].y+fx[a][1]]=='.')
						ll++;
					if (mp[p[j].x+fx[b][0]][p[j].y+fx[b][1]]=='.')
						ll++;
					if (ll==k && min>t)
						min=t;
				}
			}
		}
		if (min!=20)
			printf("%d\n",min);
		else
			printf("-1\n");
	}
	return 0;
}
