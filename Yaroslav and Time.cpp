#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int d[110][110],a[110],x[110],y[110];
int dis (int x,int y,int x1,int y1)
{
	return (fabs(x-x1)+fabs(y-y1));
}
int main()
{
	int n,h,i,j,k;
	while (~scanf("%d%d",&n,&h))
	{
		for (i=2;i<=n-1;i++)
			scanf("%d",&a[i]);
		memset(d,0,sizeof(d));
		for (i=1;i<=n;i++)
		{
			scanf("%d%d",&x[i],&y[i]);
			for (j=1;j<=i;j++)
			if (i!=j)
				d[i][j]=d[j][i]=dis(x[j],y[j],x[i],y[i])*h;
		}
		for (k=1;k<=n;k++)
			for (i=1;i<=n;i++)
				for (j=1;j<=n;j++)
					if (d[i][j]>d[i][k]+d[k][j]-a[k] && i!=j && i!=k && j!=k)
						d[i][j]=d[i][k]+d[k][j]-a[k];
		printf("%d\n",d[1][n]);
	}
	return 0;
}

