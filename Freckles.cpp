#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
#define M 0x7fffffff
float f[110][110];
int vis[110];
struct point
{
	float x,y;
}p[1010];
float ff(point a,point b)
{
	return ( sqrt( (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y) ) );
}
int main()
{
	int T,n,i,j;
	while(~scanf("%d",&n))
	{
		for (i=1;i<=n;i++)
		{
			vis[i]=1;
			scanf("%f%f",&p[i].x,&p[i].y);
			for (j=1;j<=i-1;j++)
			{
				float k=ff(p[j],p[i]);
				f[i][j]=f[j][i]=k;
			}
		}
		vis[1]=0;
		float s=0;
		for (i=2;i<=n;i++)
		{
			float max=M;
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
		printf("%.2f\n",s);
	}
	return 0;
}
