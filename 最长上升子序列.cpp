#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int n,i,a[100],b[100];
	scanf("%d",&n);
	for (i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int top=0;
	memset(b,0,sizeof(b));
	for (i=0;i<=n;i++)
	{
			int low=0,high=top,mid;
			while (low<=high)
			{
				mid=(low+high)/2;
				if (a[i]>b[mid])
					low=mid+1;
				else high=mid-1;
			}
			b[low]=a[i];
			if (low>top) top++;
	}
	for (i=1;i<=top;i++)
		cout<<b[i]<<" ";
	return 0;
}
