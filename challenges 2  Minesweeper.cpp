#include <cstdio>
#include <cstring>
int map[110][110];
void ff(int x,int y)
{
	if ( (x-1>0) && (y-1>0) && map[x-1][y-1]!=-1)
	map[x-1][y-1]++;
	if ( (x-1>0) && (y>0) && map[x-1][y]!=-1)
	map[x-1][y]++;
	if ( (x-1>0) && (y+1>0) && map[x-1][y+1]!=-1)
	map[x-1][y+1]++;
	if ( (x>0) && (y-1>0) && map[x][y-1]!=-1)
	map[x][y-1]++;
	if ( (x>0) && (y+1>0) && map[x][y+1]!=-1)
	map[x][y+1]++;
	if ( (x+1>0) && (y-1>0) && map[x+1][y-1]!=-1)
	map[x+1][y-1]++;
	if ( (x+1>0) && (y>0) && map[x+1][y]!=-1)
	map[x+1][y]++;
	if ( (x+1>0) && (y+1>0) && map[x+1][y+1]!=-1)
	map[x+1][y+1]++;
}
int main()
{
	int n,m,t=1;
	scanf("%d%d",&n,&m);
	while ((n+m))
	{
		memset(map,0,sizeof(map));
		for (int i=1;i<=n;i++)
		{
			getchar();
			for (int j=1;j<=m;j++)
			{
				char c;
				scanf("%c",&c);
				if (c=='*')
				map[i][j]=-1;
			}
		}
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
			if (map[i][j]==-1)
			ff(i,j);
		printf("Field #%d:\n",t++);
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=m;j++)
			if (map[i][j]==-1)
			printf("*");
			else 
			printf("%d",map[i][j]);
			printf("\n");		
		}
		scanf("%d%d",&n,&m);
		if (n+m) printf("\n");
	} 
	return 0;
}
