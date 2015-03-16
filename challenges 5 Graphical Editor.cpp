#include <cstdio>
#include <cstring>
int x,x1,x2,y,y1,y2,n,m;
char k;
char p[300][300];
void fc()
{
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
	p[i][j]='O';
}
void fl(int x,int y,char c)
{
	p[y][x]=c;
}
void fv(int x,int y1,int y2,char c)
{
	if (y1>y2)
	{
		int t=y1;
		y1=y2;
		y2=t;
	}
	for (int i=y1;i<=y2;i++)
	p[i][x]=c;
}
void fh(int x1,int x2,int y,char c)
{
	if (x1>x2)
	{
		int t=x1;
		x1=x2;
		x2=t;
	}
	for (int i=x1;i<=x2;i++)
	p[y][i]=c;
}
void fk(int x1,int x2,int y1,int y2,char c)
{
	for (int i=y1;i<=y2;i++)
	for (int j=x1;j<=x2;j++)
	p[i][j]=c;
}
void ff(int x,int y,char c,char c1)
{
	if (p[y][x]==c || p[y][x]!=c1)
	return;
	p[y][x]=c;
	ff(x-1,y,c,c1);
	ff(x+1,y,c,c1);
	ff(x,y-1,c,c1);
	ff(x,y+1,c,c1);
}
void fs()
{
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		printf("%c",p[i][j]);
		printf("\n");
	}
}
int main()
{
	char c;
	while (~scanf("%s",&c)&& c!='X')
	{
		if (c=='I')
		{
			scanf("%d%d",&m,&n);
			fc();
		}
		else 
		if (c=='C')
			fc();
		else 
		if (c=='L')
		{
			scanf("%d %d %c",&x,&y,&k);
			fl(x,y,k);
		}
		else if (c=='V')
		{
			scanf("%d %d %d %c",&x,&y1,&y2,&k);
			fv(x,y1,y2,k);
		}
		else if (c=='H')
		{
			scanf("%d %d %d %c",&x1,&x2,&y,&k);
			fh(x1,x2,y,k);
		}
		else if(c=='K')
		{
			scanf("%d %d %d %d %c",&x1,&x2,&y1,&y2,&k);
			fk(x1,x2,y1,y2,k);
		} 
		else if (c=='F')
		{
			char k1;
			scanf("%d %d %c",&x,&y,&k);
			k1=p[y][x];
			ff(x,y,k,k1);
		}
		else if (c=='S')
		{
			char ss[1000];
			scanf("%s",&ss);
			puts(ss);
			fs();
		}
		else 
		{
			char ss[1000];
			gets(ss);
			continue;
		}
	}
	return 0;
} 
