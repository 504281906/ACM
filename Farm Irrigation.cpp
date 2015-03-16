#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int f[5000];
char c[60][60];
int n,m,x1,y1;
int find(int n)
{
	if (n!=f[n]) f[n]=find(f[n]);
		return f[n];
}
void shang(char a,char b,int x,int y)
{
	if ((a=='C' ||a=='D' ||a=='E' ||a=='H' ||a=='I' ||a=='J' ||a=='K')&&
		(b=='A' || b=='B' || b=='E' || b=='G' || b=='H' || b=='J' || b=='K'))
	{
		x1=find((x-1)*m+y);
		y1=find((x-2)*m+y);
		f[y1]=x1;
	}
}
void zuo(char a,char b,int x,int y)
{
	if ((a=='B' ||a=='D' ||a=='F' ||a=='G' ||a=='I' ||a=='J' ||a=='K')&&
		(b=='A' || b=='C' || b=='F' || b=='G' || b=='H' || b=='I' || b=='K'))
	{
		x1=find((x-1)*m+y);
		y1=find((x-1)*m+y-1);
		f[y1]=x1;
	}
}
void panduan(int x,int y)
{
	if (x>1) shang(c[x-1][y],c[x][y],x,y);
	if (y>1) zuo(c[x][y-1],c[x][y],x,y);
}
int main()
{
	int i,j,t;
	while (~scanf("%d%d",&n,&m) && (n+m)>0)
	{
		for (i=1;i<=n*m+5;i++)
			f[i]=i;
		for (i=1;i<=n;i++)
		{
			getchar();
			for (j=1;j<=m;j++)
			{
				scanf("%c",&c[i][j]);
				panduan(i,j);
			}
		}
		t=0;
		for (i=1;i<=n*m;i++)
		if (i==f[i]) t++;
		cout<<t<<endl;
	}
	return 0;
}
