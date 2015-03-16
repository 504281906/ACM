#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define INF 0x3fffffff
int n,tax[1010],f[1010][1010],p[1010][1010];
int main()
{
	while (~scanf("%d",&n) && n)
	{
		for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
		{
			scanf("%d",&f[i][j]);
			if (f[i][j]==-1)
			f[i][j]=INF;
			p[i][j]=j;
		}
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&tax[i]);
		}
		int begin,end;
		for (int k=1;k<=n;k++)
			for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
			if (k!=i&& k!=j && i!=j)
			{
			if ((f[i][j]>f[i][k]+f[k][j]+tax[k]))
				{
					f[i][j]=f[i][k]+f[k][j]+tax[k];
					p[i][j]=p[i][k];
				}
			else 
			if ((f[i][j]==f[i][k]+f[k][j]+tax[k]) && (p[i][j]>p[i][k]))
				p[i][j]=p[i][k];
			}	
		while (~scanf("%d%d",&begin,&end)&& (begin!=-1))
		{
			int b[1010],k=1;
			memset(b,0,sizeof(b));
			b[k]=end;
			while (p[begin][b[k]]!=b[k])
			{
				k++;
				b[k]=p[begin][b[k-1]];
			}
			b[++k]=begin;
			printf("From %d to %d :\nPath: ",begin,end);
			if (begin!=end) 
			for (int i=k;i>1;i--)
			printf("%d-->",b[i]);
			printf("%d",b[1]);
			printf("\nTotal cost : ");
			printf("%d\n\n",f[begin][end]);
		}
	}
	return 0;
}
