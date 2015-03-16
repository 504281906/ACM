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
#include <ctime>
#define LL __int64
#define EPS 1e-8
#define inf 0x3fffffff
using namespace std;
int f[10];
double dp[1101][110][10];
double cal(int p1,int p2,int t1,int t2,int p)
{
	if (p>=p2)
		return t2;
	if (p<p1)
		return inf;
	return t1*1.0-1.0*(p-p1)*(t1-t2)/(p2-p1);
}
int main()
{
	int i,j,k,l,p1,p2,t1,t2,n,w1,w2,p;
	f[0]=1;
	for (i=1;i<8;i++)
		f[i]=f[i-1]*2;
	while (~scanf("%d%d",&n,&p) && (n+p))
	{
		int w=0;
		scanf("%d%d%d%d%d%d",&p1,&p2,&t1,&t2,&w1,&w2);
		for (i=1;i<=n;i++)
			for (j=1;j<=100;j++)
				for (k=0;k<=7;k++)
					dp[i][j][k]=inf;
		dp[1][min(100,p+w1)][min(7,w2)]=cal(p1,p2,t1,t2,p);
		p+=w1;
		for (i=2;i<=n;i++)
		{
			scanf("%d%d%d%d%d%d",&p1,&p2,&t1,&t2,&w1,&w2);
			for (j=1;j<=100;j++)
				for (k=0;k<=7;k++)
					for (l=0;l<=k;l++)
					{
						int np=j*f[l]+w1;
						int mw=k+w2-l;
						double t=cal(p1,p2,t1,t2,j*f[l]);
						dp[i][min(np,100)][min(mw,7)]=min(dp[i][min(np,100)][min(mw,7)],dp[i-1][j][k]+t);
					}
		}
		double ans=inf;
		for (i=1;i<=100;i++)
			for (j=0;j<=7;j++)
				if (ans>dp[n][i][j])
					ans=dp[n][i][j];
		if (fabs(ans-inf)<EPS)
			printf("Impossible\n");
		else printf("%.2lf\n",ans);
	}
	return 0;
}
