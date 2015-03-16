#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
double dp[110];
int p[110];
int main()
{
	int l,n,c,t,i,j,vr,vt1,vt2;
	while (~scanf("%d",&l))
	{
		scanf("%d%d%d",&n,&c,&t);
		scanf("%d%d%d",&vr,&vt1,&vt2);
		for (i=1;i<=n;i++)
			scanf("%d",&p[i]);
		memset(dp,0,sizeof(dp));
		double t1=c*1.0/vt1;
		p[0]=0;p[n+1]=l;
		for (i=1;i<=n+1;i++)
		{
			for (j=0;j<i;j++)
			{
				double s;
				if (p[i]-p[j]<=c) 
					s=dp[j]+(p[i]-p[j])*1.0/vt1;
				else
					s=dp[j]+t1+(p[i]-p[j]-c)*1.0/vt2;
				if (j>0) s+=t;
				if (dp[i]>s || dp[i]==0)
					dp[i]=s;
			}
		}
		//printf("%lf\n",dp[n+1]);
		if (dp[n+1]<l*1.0/vr)
			printf("What a pity rabbit!\n");
		else printf("Good job,rabbit!\n");
	}
	return 0;
}
