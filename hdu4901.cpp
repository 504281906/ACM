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
using namespace std;
#define LL long long
const LL M=1e9+7;
int a[1010];
LL s[1010][1050],t[1010][1050];
int main()
{
	int T,i,n,j;
	scanf("%d",&T);
	while (T--)
	{
		memset(s,0,sizeof(s));
		memset(t,0,sizeof(t));
		scanf("%d",&n);
		for (i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			s[i][a[i]]=1;
			for (j=0;j<=1024;j++)
				if (s[i-1][j])
				{
					s[i][j]=(s[i][j]+s[i-1][j]) % M;
					s[i][j^a[i]]=(s[i][j^a[i]]+s[i-1][j]) % M;
				}
		}
		LL ans=0;
		for (i=n;i>1;i--)
		{
			t[i][a[i]]=1;
			ans=(ans+s[i-1][a[i]]) % M;
			int b[1050];
			memset(b,0,sizeof(b));
			for (j=0;j<=1024;j++)
			if (t[i+1][j])
			{
				ans=(ans+s[i-1][j&a[i]]*t[i+1][j]) % M;
				b[j&a[i]]=(b[j&a[i]]+t[i+1][j]) % M;
			}
			for (j=0;j<=1024;j++)
				t[i][j]=(t[i][j]+b[j]+t[i+1][j]) % M;
		}
		printf("%I64d\n",ans % M);
	}
	return 0;
}
