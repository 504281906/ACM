#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
double M;
double f[1010][1010];
int vis[1010];
struct point
{
	double x,y;
}p[1010];
double ff(point a,point b)
{
	return ( sqrt( (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y) ) );
}
int main()
{
	int T,n,i,j,m;
	while(~scanf("%d%d",&n,&m))
	{
		for (i=1;i<=n;i++)
		{
			vis[i]=1;
			scanf("%lf%lf",&p[i].x,&p[i].y);
			for (j=1;j<=i-1;j++)
			{
				double k=ff(p[j],p[i]);
				f[i][j]=f[j][i]=k;
				if (M<k) M=k;
			}
		}
		for (j=1;j<=m;j++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			f[a][b]=f[b][a]=0;
		}
		vis[1]=0;
		double s=0;
		for (i=2;i<=n;i++)
		{
			double max=M;
			int pos=0;
			for (j=1;j<=n;j++)
			if ((vis[j]) && (f[1][j]<max))
			{
				max=f[1][j];
				pos=j;
			}
			s+=max;
			vis[pos]=0;
			for (j=1;j<=n;j++)
				if (vis[j] && (f[pos][j]<f[1][j]))
					f[1][j]=f[pos][j];
		}
		printf("%.2lf\n",s);
	}
	return 0;
}	
