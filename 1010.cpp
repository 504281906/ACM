#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct node 
{
	int x,y;
}p[3];
int n,m,t,ff;
int vist[100][100];
int f[4][2]={0,1,0,-1,1,0,-1,0};
int CutBranch(int i, int j)
{
    return abs(i - p[2].x) + abs(j - p[2].y);
}
int DFS(int xx,int yy,int T)
{
	int a = CutBranch(xx, yy);
    if((a & 1) != ((t - T) & 1) || a > t - T) return 0;
	if (T==t && ((xx!=p[2].x) || (yy!=p[2].y))) return ff;
	if ((xx==p[2].x) && (yy==p[2].y) && (T==t))
	{
		ff=1;
		return ff;
	}
	for (int i=0;i<4;i++)
	{
		int xxx=xx+f[i][0];
		int yyy=yy+f[i][1];
		if ((!vist[xxx][yyy]) && (xxx>0) && (xxx<=n) && (yyy<=m) && (yyy>0))
		{
			vist[xxx][yyy]=1;
			T++; 
			DFS(xxx,yyy,T);
			if (ff) return 1;
			T--;
			vist[xxx][yyy]=0;
		}
	}
}
int main()
{
	while (~scanf("%d%d%d",&n,&m,&t)&&(n+m+t))
	{
		int tt=0;
		memset(vist,0,sizeof(vist));
		getchar();
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=m;j++)
			{
				char c;
				scanf("%c",&c);
				if (c=='S') 
				{
					p[1].x=i;
					p[1].y=j;
					vist[i][j]=1;
				}
				if (c=='D')
				{
					p[2].x=i;
					p[2].y=j;
				}
				if (c=='X')
				{
					vist[i][j]=1;
					tt++;
				}
			}
			getchar();
		}
		ff=0;
		if (t>n*m-tt) puts("NO");
		else 
		{
			DFS(p[1].x,p[1].y,0);
			if (ff==0) printf("NO\n");
				else printf("YES\n");
		}
	}
	return 0;
}
