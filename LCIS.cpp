#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int n,m,a[5100],b[5100],f[5100];
int LCIS()
{
	int i,j,k;
	memset(f,0,sizeof(f));
	for (i=0;i<n;i++)
	{
		k=-1;
		for (j=0;j<m;j++)
		{
			if (b[i]==a[j])
			{
				if (f[j]<f[k]+1)
					f[j]=f[k]+1;
			}
			else if (b[i]>a[j])
			{
				if (f[j]>f[k])
					k=j;
			}
		}
	}
	int ans=0;
	for (i=0;i<m;i++)
		if (ans<f[i])
			ans=f[i];
	return ans;
}
int main()
{
	int T,i;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&m);
		for (i=0;i<m;i++)
			scanf("%d",&a[i]);
		scanf("%d",&n);
		for (i=0;i<n;i++)
			scanf("%d",&b[i]);
		printf("%d\n",LCIS());
		//if (T) printf("\n");
	}
	return 0;
}
