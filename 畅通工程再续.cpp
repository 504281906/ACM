#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
#define M 5000
double f[110][110];
int vis[110];
struct point
{
	int x,y;
}p[1010];
double ff(point a,point b)
{
	return ( sqrt( (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y) ) );
}
int main()
{
	int T,n,i,j;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (i=1;i<=n;i++)
		{
			vis[i]=1;
			scanf("%d%d",&p[i].x,&p[i].y);
			for (j=1;j<=i-1;j++)
			{
				double k=ff(p[j],p[i]);
				if (k<10.0 || k>1000.0) k=M;
				f[i][j]=f[j][i]=k;
			}
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
			if (pos==0) break;
			s+=max;
			vis[pos]=0;
			for (j=1;j<=n;j++)
				if (vis[j] && (f[pos][j]<f[1][j]))
					f[1][j]=f[pos][j];
		}
		if (i!=n+1) cout<<"oh!"<<endl;
		else printf("%.1lf\n",s*100.00);
	}
	return 0;
}
