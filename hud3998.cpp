#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int f[10010],a[10010];
int main()
{
	int n,i,j;
	while (~scanf("%d",&n))
	{
		for (i=0;i<n;i++)
			scanf("%d",&a[i]);
		memset(f,0,sizeof(f));
		for (i=1;i<n;i++)
		{
			int k=0,s=0;
			for (j=0;j<i;j++)
			{
				if (a[i]>a[j])
					if (s<f[j]+1) 
					{
						s=f[k]+1;
						k=j;
					}
			}
			f[i]=s;
			f[k]=0;
		}
		int ans=0,k=0;
		for (i=0;i<n;i++)
		{
			if (ans<f[i])
			{
				ans=f[i];
				k=1;
			}
			else if (ans==f[i]) k++;
		}
		printf("%d %d\n",ans,k);
	}
	return 0;
}

