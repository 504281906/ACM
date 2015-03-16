#include <stdio.h>
#include <math.h>
#include <string.h>
#define INF 0x7fffffff
double f[60][60];
double ff(int x1,int y1,int x2,int y2)
{
	return (sqrt((y2-y1)*(y2-y1)+(x2-x1)*(x2-x1)));
}
double minx(double x,double y)
{
	return x<y?x:y;
}
int main()
{
	int x[60],y[60];
	int vist[60];
	int n,p,q;
	while (~scanf("%d",&n)&&n)
	{
		memset(vist,0,sizeof(vist));
		scanf("%d%d",&p,&q);
		for (int i=1;i<=n;i++)
		{
			scanf("%d%d",&x[i],&y[i]);
			for (int j=1;j<i;j++)
				f[j][i]=f[i][j]=ff(x[j],y[j],x[i],y[i]);
		}
		double s=f[p][q];
		vist[p]=1;
		vist[q]=1;
		for (int i=1;i<=n;i++)
			f[p][i]=minx(f[p][i],f[q][i]);
		f[p][q]=f[q][p]=INF;
		int T=n-2;
		while (T--)
		{
			int pos;
			double m=INF;
			for (int i=1;i<=n;i++)
			if (!vist[i] && m>f[p][i])	
			{
				m=f[p][i];
				pos=i;
			}
			s+=m;
			vist[pos]=1;
			for (int i=1;i<=n;i++)
			{
				if (!vist[i] && f[p][i]>f[pos][i])
					f[p][i]=f[pos][i];
			}
		}
		printf("%0.2lf\n",s);
	}
	return 0;
}
