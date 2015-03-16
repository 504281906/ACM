#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int a[30];
int b[30][52];
int main()
{
	int T,i,j,k;
	scanf("%d",&T);
	while (T--)
	{
		memset(b,0,sizeof(b));
		for (i=1;i<=26;i++)
			scanf("%d",&a[i]);
		for (i=0;i<=26;i++)
			b[i][0]=1;
		for (i=1;i<=26;i++)
		{
			for (j=1;j<=50;j++)
			{
				b[i][j]=b[i-1][j];
				for (k=1;k<=a[i];k++)
					if (j-k*i>=0)
						b[i][j]+=b[i-1][j-k*i];
			}
		}
		long long ans=0;
		for (i=1;i<=50;i++)
			ans+=b[26][i];
		printf("%lld\n",ans);
	}
	return 0;
}

