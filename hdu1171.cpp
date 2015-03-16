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
int v[55],m[55],c1[560010],c2[560010];
int n,i,j,k,s;
int main()
{
	while (~scanf("%d",&n) && n>=0)
	{
		s=0;
		for (i=1;i<=n;i++)
		{
			scanf("%d%d",&v[i],&m[i]);
			s+=v[i]*m[i];
		}
		memset(c1,0,sizeof(c1));
		memset(c2,0,sizeof(c2));
		for (i=0;i<=s && i/v[1]<=m[1];i+=v[1])
			c1[i]=1;
		for (i=2;i<=n;i++)
		{
			for (j=0;j<=s;j++)
				if (c1[j])
					for (k=0;k+j<=s && k/v[i]<=m[i];k+=v[i])
						c2[k+j]+=c1[j];
			for (j=0;j<=s;j++)
			{
				c1[j]=c2[j];
				c2[j]=0;
			} 
		}
		for (i=(s+1)/2;i<=s;i++)
			if (c1[i])
			{
				printf("%d %d\n",i,s-i);
				break;
			}
	}
	return 0;
}
