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
using namespace std;
int c1[100],c2[100],v[50],n[50];
int main()
{
	int T,i,j,k;
	scanf("%d",&T);
	while (T--)
	{
		int t=1;
		for (i=1;i<=26;i++)
		{
			scanf("%d",&k);
			if (k>0)
			{
				v[t]=i;
				n[t]=k;
				t++;
			}
		}
		t--;
		memset(c1,0,sizeof(c1));
		memset(c2,0,sizeof(c2));
		for (i=0;i<=50 && i/v[1]<=n[1];i+=v[1])
			c1[i]=1;
		for (i=2;i<=t;i++)
		{
			for (j=0;j<=50;j++)
			{
				if (c1[j])
				for (k=0;k<=50 && k/v[i]<=n[i];k+=v[i])
					c2[k+j]+=c1[j];
			}
			for (j=0;j<=50;j++)
			{
				c1[j]=c2[j];
				c2[j]=0;
			}
		}
		int ans=0;
		for (i=1;i<=50;i++)
			ans+=c1[i];
		cout<<ans<<endl;
	}
	return 0;
}
