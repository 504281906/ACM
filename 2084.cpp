#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int a[110][110],f[110][110];
int main()
{
	int T,n,i,j;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		memset(f,0,sizeof(0));
		memset(a,0,sizeof(0));
		for (i=1;i<=n;i++)
			for (j=1;j<=i;j++)
			{
				scanf("%d",&a[i][j]);
				f[i][j]=max(f[i-1][j-1],f[i-1][j])+a[i][j];
			}
		int max=0;
		for (i=1;i<=n;i++)
			if (max<f[n][i])	
				max=f[n][i];
		cout<<max<<endl;
	}
	return 0;
}

