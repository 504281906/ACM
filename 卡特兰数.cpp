#include <cstdio>
#include <algorithm>
#include <cstring>
const int l=110;
int f[200][200];
int ktl()
{
	f[0][0]=1;
	int n; 
	for (int i=1;i<=100;i++)
	{
		n=4*i-2;
		for (int j=0;j<=l;j++)
		{
			f[i][j]+=f[i-1][j]*n;
			if (f[i][j]>=10)
			{
				f[i][j+1]+=f[i][j]/10;
				f[i][j]=f[i][j]% 10;
			}
		}
		n=i+1;
		int ys=0;
		for (int j=l;j>=0;j--)
		{
			int p=(10*ys+f[i][j])/n;
			ys=(10*ys+f[i][j])%n;
			f[i][j]=p;
		}
	}
	return 0;
}
int main()
{
	memset(f,0,sizeof(f)); 
	ktl();
	int kk;
	while (~scanf("%d",&kk))
	{
		int j=l;
		while (f[kk][j]==0) j--;
		for (int k=j;k>=0;k--)
			printf("%d",f[kk][k]);
			printf("\n");
	}
	return 0;
}
//C(2n,n)/(n+1);
