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
int n,m,i,j,l;
int a[1010][1010];
int main()
{
	while (~scanf("%d%d",&m,&n))
	{
		memset(a,0,sizeof(a));
		for (i=1;i<=n;i++)
			for (j=1;j<=m;j++)
				scanf("%d",&a[i][j]);
		long long s=0;		
		for (i=1;i<=n;i++)
		{
			if (n-i+1<=s) break;
			for (j=1;j<=m;j++)
			{
				if (m-j+1<=s) break;
				if (a[i][j])
				{
					int k=1;	
					if (s<k) s=k;
					int j2=j+1;
					while (a[i][j2] && a[i+k][j])
					{
						int flag=1;
						for (l=1;l<=k;l++)
							if (a[i+k][j+l]==0 || a[i+l][j2]==0)
							{
								flag=0;
								break;
							}
						if (!flag) break;
						k++;
						if (s<k) s=k;
						j2++;			
					}
				}
			}
		}
		printf("%lld\n",s*s);
	} 
	return 0;
}
