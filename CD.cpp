#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int a[111111];
int k[111111];
int f[111111];
int b[111111];
int main()
{
	int n,m,i,j;
	while (~scanf("%d%d",&n,&m))
	{
		memset(k,0,sizeof(k));
		memset(f,0,sizeof(f));
		memset(b,0,sizeof(b));
		for (i=1;i<=m;i++)
			scanf("%d",&a[i]);
		for (i=1;i<=m;i++)
			for (j=n;j>0;j--)
			if (j==a[i] && f[j]==0)
			{
				k[j]=a[i];
				f[j]=a[i];
			}
			else if (f[j] && f[j+a[i]]==0) 
			{
				f[j+a[i]]=j+a[i];
				k[j+a[i]]=a[i];
			}
		for (i=n;i>0;i--)
			if (f[i]!=0)
			{
				int hh=i;
				for (j=1;i;j++)
				{
					b[j]=k[i];
					i-=k[i];
				}
				j--;
				for (int h=j;h>=1;h--)
					printf("%d ",b[h]);
				printf("sum:%d\n",hh);
				break;
			}
	}
	return 0;
}
