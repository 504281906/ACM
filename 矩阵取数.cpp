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
int a[105][105];
int f[105][105];
int main()
{
	int T,i,j,k,l,n,m;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&m);
		for (i=1;i<=n;i++)
			for (j=1;j<=m;j++)
			{
				scanf("%d",&f[i][j]);
				if (i==1) a[i][j]=f[i][j];
			}
		for (i=2;i<=n;i++)
			for (j=i;j<=m;j++)
			{
				a[i][j]=a[i-1][j-1]+f[i][j];
				for (k=1;k<j;k++)
					for (l=1;l<i;l++)
						if (a[i][j]>a[i-1][k]-f[l][k]+f[i][k]+f[l][j])
							a[i][j]=a[i-1][k]-f[l][k]+f[i][k]+f[l][j];
			}
		cout<<a[n][m]<<endl;
	}
	return 0;
}

