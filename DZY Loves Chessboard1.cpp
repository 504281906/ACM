#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int n,m,i,j;
int vis[105][105];
char c;
int main()
{
	while (scanf("%d%d",&n,&m)==2)
	{
		memset(vis,0,sizeof(vis));
		for (i=0;i<n;i++)
		{
			getchar();
			for (j=0;j<m;j++)
			{
				scanf("%c",&c);
				if (c=='-') continue;
				else
					vis[i][j]=(i+j)%2+2;
			}
		}
		for (i=0;i<n;i++)
		{
			for (j=0;j<m;j++)
			{
				if (vis[i][j]==0)
					printf("-");
				else if (vis[i][j]==2)
					printf("B");
				else printf("W");
			}
			printf("\n");
		}
	}	
}
