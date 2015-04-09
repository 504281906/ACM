#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int f[10001][200];
int main()
{
	int i,n,j;
	memset(f,0,sizeof(f));
	f[1][0]=1;f[1][1]=1;
	for (i=2;i<=10000;i++)
	{
		int k=0;
		int h=1;
		j=1;
		while (f[i-1][j]==0) j++;
		for (j;j<=f[i-1][0];j++)
		{
			k=f[i-1][j]*i+k;
			f[i][h++]=k % 10;
			k=k / 10;
			if (h>120) break;
		}
		while (k)
		{
			f[i][h++]=k % 10;
			k/=10;
			if (h>120) break;
		}
		f[i][0]=h-1;
	}
	int m,T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&m);	
		i=1;
		while (f[n][i]==0) i++;
		printf("%d\n",f[n][i+m-1]);
	}
	return 0;
}
