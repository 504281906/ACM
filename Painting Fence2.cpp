#include <bits/stdc++.h>
using namespace std;
int a[5010];
int n;
int gogogo(int l,int r)
{
	int len=r-l+1;
	int max=a[l],ans=0;
	for (int i=l;i<=r;i++)
		if (a[i]<max)
			max=a[i];
	for (int i=l;i<=r;i++)
		a[i]-=max;
	ans=max;
	for (int i=l;i<=r;i++)
	{
		if (a[i]!=0)
		{
			int l1=i,r1=i+1;
			while (a[r1]!=0 && r1<=r)
				r1++;
			r1--;
			ans+=gogogo(l1,r1);
		}
	}
	if (len<ans)
		ans=len;
	return ans;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	cout<<gogogo(1,n)<<endl;
	return 0;
}
