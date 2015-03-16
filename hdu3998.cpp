#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int f[10010],a[10010],vis[10010];
int ff(int low,int high,int n)
{
	while (low<=high)
	{
		int mid=(low+high)/2;
		if (f[mid]==n) return mid;
		if (f[mid]>n) high=mid-1;
		else low=mid+1;
	}
	return low;
}
int main()
{
	int n,i,j;
	while (~scanf("%d",&n))
	{
		int ans=0,t=0;
		for (i=0;i<n;i++)
			scanf("%d",&a[i]);
		memset(f,0,sizeof(f));
		memset(vis,0,sizeof(vis));
		//f[0]=-1;
		while (1)
		{
			int k=0;
			for (i=0;i<n;i++)
			{
				if (vis[i]) continue;
				int pos=ff(0,k,a[i]);
				f[pos]=a[i];
				if (pos>k)
				{
					k++;
					vis[i]=1;
				}
			}
			if (ans<k) 
			{
				ans=k;
				t=1;
			}
			else if (ans==k) t++;
			else break;
		}
		printf("%d\n%d\n",ans,t);
	}
	return 0;
}

