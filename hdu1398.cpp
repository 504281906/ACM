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
int c1[310],c2[310],v[20];
int i,j,k,n;
int main()
{
	for (i=1;i<=17;i++)
		v[i]=i*i;
	for (i=0;i<=300;i++)
			c1[i]=1;
	memset(c2,0,sizeof(c2));
	for (i=2;i<=17;i++)
	{
		for (j=0;j<=300;j++)
			if (c1[j])
				for (k=0;k+j<=300;k+=v[i])
					c2[k+j]+=c1[j];
		for (j=0;j<=300;j++)
		{
			c1[j]=c2[j];
			c2[j]=0;
		}
	}
	while (~scanf("%d",&n) && n)
	{
		cout<<c1[n]<<endl;
	}
	return 0;
}
