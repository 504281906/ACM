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
int a[1010][1010];
int main()
{
	int n,m,s,i,j,k;
	while (~scanf("%d%d",&n,&m))
	{
		s=0;
		memset(a,0,sizeof(a));
		for (i=1;i<=n;i++)
			for (j=1;j<=m;j++)
			{
				scanf("%d",&k);
				if (k)
					a[i][j]=min(a[i-1][j]+1,a[i][j-1]+1);
				else 
					a[i][j]=0;
			}
		for (i=1;i<=n;i++)
			for (j=1;j<=m;j++)
			{
				k=min(i,j)-1;
				int flag=1,h=0;
				for (int l=1;l<=k;l++)
					if (a[i-l][j-l]+l<a[i][j])
					{
						flag=0;
						break;
					}
				if (flag && s<a[i][j]) s=a[i][j]; 
			}
		cout<<s*s<<endl;
	}
	return 0;
}
