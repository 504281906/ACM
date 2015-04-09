#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
int x[4]={0,-1,0,1};
int y[4]={-1,0,1,0};
using namespace std;
int main()
{
	int n;
	int m[110][110];
	while (~scanf("%d",&n))
	{
		memset(m,0,sizeof(m));
		m[n][n]=n*n;
		int i=n,j=n;
		int s=n*n-1;
		int t=0;
		int ans=n*n;
		while (s)
		{
			if (i+x[t]==0 || j+y[t]==0 || j+y[t]>n || m[i+x[t]][j+y[t]]!=0)
				t=(t+1) % 4;
			i+=x[t];
			j+=y[t];
			m[i][j]=s;
			if (i==j || i==(n-j+1)) ans+=s;
			s--;
		}
		for (i=1;i<=n;i++)
		{
			for (j=1;j<n;j++)
				printf("%d ",m[i][j]);
			printf("%d\n",m[i][n]);
		}
		printf("%d\n",ans);
	}
	return 0;
}
