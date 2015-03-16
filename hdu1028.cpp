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
int c1[125],c2[125],n,i,j,k;
int main()
{
	while (~scanf("%d",&n))
	{
		for (i=0;i<=n;i++)
		{
			c1[i]=1;
			c2[i]=0;
		}
		for (i=2;i<=n;i++)
		{
			for (j=0;j<=n;j++)
			{
				if (c1[j])
				for (k=0;k+j<=n;k+=i)
					c2[k+j]+=c1[j];
			}
			for (j=0;j<=n;j++)
			{
				c1[j]=c2[j];
				c2[j]=0;
			}
		}
		cout<<c1[n]<<endl;
	}
	return 0;
}
