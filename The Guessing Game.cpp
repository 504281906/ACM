#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int n,m,l,Min,T;
int v[11][11],mp[11][11],hang[11],lie[11],xie[21];
/*int ff()
{
	int i,j;
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
			if (v[i][j]!=mp[i][j]) return 1;
	return 0;
}*/
void fff(int k,int k2)
{
	int i,j;
	if (k==l && hang[1]-xie[l]==0 && lie[m]-xie[l]==0/* && (ff() || T==0)*/)
	{
		T++;
		mp[1][m]=xie[l];
		if (T==1)
		for (i=1;i<=n;i++)
			for (j=1;j<=m;j++)
				v[i][j]=mp[i][j];	
	/*	for (i=1;i<=n;i++)
			{
				for (j=1;j<=m;j++)
					if (v[i][j]==1) printf("X");
					else printf(".");
				printf("\n");
			}
		printf("\n");*/
		return;
	}
	if (xie[k]==0) fff(k+1,1);
	if (k<=n)
	{
		int k1=min(Min,k);
		if (xie[k]>k1-k2+1) return;
		for (i=k2;i<=k1;i++)
		{
			if (xie[k]>k1-i+1) return;
			if (hang[n-k+i]>0 && lie[i]>0 && mp[n-k+i][i]==0)
			{
				hang[n-k+i]--;
				lie[i]--;
				xie[k]--;
				mp[n-k+i][i]=1;
				fff(k,i+1);
				hang[n-k+i]++;
				lie[i]++;
				xie[k]++;
				mp[n-k+i][i]=0;
			}
		}
		if (xie[k]>0) return;
	}
	else 
	{
		int k1=min(Min,l-k+1);
		if (xie[k]>k1-k2+1) return;
		for (i=k2;i<=k1;i++)
		{
			if (xie[k]>k1-i+1) return;
			if (hang[i]>0 && lie[i+k-n]>0 && mp[i][i+k-n]==0)
			{
				hang[i]--;
				lie[i+k-n]--;
				xie[k]--;
				mp[i][i+k-n]=1;
				fff(k,i+1);
				hang[i]++;
				lie[i+k-n]++;
				xie[k]++;
				mp[i][i+k-n]=0;
			}
		}
		if (xie[k]>0) return;
	}
}
int main()
{
	int i,j;
	while (~scanf("%d%d",&n,&m))
	{
		memset(mp,0,sizeof(mp));
		memset(v,0,sizeof(v));
		Min=m;
		if (n<m) Min=n;
		l=n+m-1;
		for (i=1;i<=n;i++)
			scanf("%d",&hang[i]);
		for (i=1;i<=m;i++)
			scanf("%d",&lie[i]);
		for (i=1;i<=l;i++)
			scanf("%d",&xie[i]);
		T=0;
		fff(1,1);
		if (T>1) printf("%d\n",T);
		else if (T==1) 
		{
			for (i=1;i<=n;i++)
			{
				for (j=1;j<=m;j++)
					if (v[i][j]==1) printf("X");
					else printf(".");
				printf("\n");
			}
		}
		printf("\n");
	}
	return 0;
}
