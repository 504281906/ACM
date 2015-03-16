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
#define eps 1e-8
using namespace std;
int a[5],b[5],c1[10000],c2[10000],q,w,e,t,i,j,k,n;
int main()
{
	while (~scanf("%d%d%d",&q,&w,&e) && (q+w+e))
	{
		n=q+2*w+5*e;
		a[1]=1;
		a[2]=2;
		a[3]=5;
		b[1]=q;
		b[2]=w;
		b[3]=e;
		memset(c1,0,sizeof(c1));
		memset(c2,0,sizeof(c2));
		for (i=0;i<=q;i++)
		{
			c1[i]=1;
			c2[i]=0;
		}
		for (i=2;i<=3;i++)
		{
			for (j=0;j<=n;j++)
			{
				if (c1[j])
				for (k=0,t=0;k+j<=n && t<=b[i];t++,k+=a[i])
					c2[k+j]+=c1[j];
			}
			for (j=0;j<=n;j++)
			{
				c1[j]=c2[j];
				c2[j]=0;
			}
		}
		for (i=0;i<=n+1;i++)
			if (!c1[i])
			{
				printf("%d\n",i);
				break;
			}
	}
	return 0;
}
