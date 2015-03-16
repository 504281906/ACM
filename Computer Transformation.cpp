#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int g[1010][500];
int f[1010][1010];
int ff(int x)
{
	int i;
	for (i=1;i<=g[x-1][0]+2;i++)
	{
		g[x][i]+=g[x-1][i]*2;
		if (g[x][i]>=10)
		{
			g[x][i+1]=g[x][i]/10;
			g[x][i]%=10;
		}
	}
	while (g[x][i]==0) i--;
	g[x][0]=i;
	return 0;
}
int fff(int x)
{
	int i;
	for (i=1;i<=g[x-2][0]+2;i++)
	{
		f[x][i]+=f[x-2][i]+g[x-2][i];
		if (f[x][i]>=10)
		{
			f[x][i+1]++;
			f[x][i]-=10;
		}
	}
	while (f[x][i]==0) i--;
	f[x][0]=i;
	return 0;
}
int main()
{
	memset(g,0,sizeof(g));
	memset(f,0,sizeof(f));
	g[1][0]=1;g[2][0]=1;
	g[1][1]=1;g[2][1]=2;
	f[2][1]=1;f[3][1]=1;
	f[2][0]=1;f[3][0]=1;
	f[1][0]=1;f[1][1]=0;
	int n;
	for (int i=3;i<=1010;i++)
	ff(i);	
	for (int i=4;i<=1010;i++)
	//f[i]=f[i-2]+g[i-2];
	fff(i);
	while (~scanf("%d",&n))
	{
		for (int i=f[n][0];i>0;i--)
		printf("%d",f[n][i]);
		printf("\n");
	}
	return 0;
}
