#include <cstdio>
#include <cstring>
#include <algorithm>
#define min(a,b) a<b?a:b
int max=0x7fffffff;
int n,a[20][20],b[20][20];
int ff(int x)
{
	memset(b,0,sizeof(b));
	for (int i=0;i<n;i++)
	{
		if (x & (1<<i)) b[0][i]=1;
			else if (a[0][i]==1) return max;
	}
	for (int i=1;i<n;i++)
		for (int j=0;j<n;j++)
		{
			int sum=0;
			if (i>1) sum+=b[i-2][j];
			if (j>0) sum+=b[i-1][j-1];
			if (j<n-1) sum+=b[i-1][j+1];
			b[i][j]=sum % 2;
			if (a[i][j]==1 && b[i][j]==0) return max;
		}
	int t=0;
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			if (a[i][j]!=b[i][j]) t++;
	return t;
}
int main()
{
	int T;
	scanf("%d",&T);
	for (int cos=1;cos<=T;cos++)
	{
		scanf("%d",&n);
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++)
				scanf("%d",&a[i][j]);
		int s=max;
		for (int i=0;i<(1<<n);i++)
		s=min(s,ff(i));
		if (s==max) s=-1;
		printf("Case %d: %d\n",cos,s);
	}
	return 0;
}
