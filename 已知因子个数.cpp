#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int k;
int z[1010];
int zhi()
{
	int i,j;
	int f[1010];
	memset(f,0,sizeof(f)); 
	for (i=2;i<1000;i++)
		if (f[i]==0)
		{
			for (j=i*i;j<=1000;j+=i)
				f[j]=1;
		}
	k=1;
	for (i=2;i<1000;i++)
	{
		if (f[i]==0)
			z[k++]=i;
	}
	k--;
}
int main()
{
	int i;
	zhi();
	for (i=1;i<=k;i++)
		printf("%d ",z[i]);
	return 0;
}

