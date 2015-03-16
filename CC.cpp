#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int a[1010];
int time (int x)
{
	if (x==1) return a[0];
	if (x==2) return a[1];
	if (x==3) return a[0]+a[1]+a[2];
	if (2*a[1]<a[0]+a[x-2])
		return (2*a[1]+a[0]+a[x-1]+time(x-2));
	else 
		return (2*a[0]+a[x-1]+a[x-2]+time(x-2));
}
void ff(int x)
{
	if (x==1)
	{
		cout<<a[0]<<endl;
		return;
	}
	if (x==2)
	{
		cout<<a[0]<<" "<<a[1]<<endl;
		return;
	}
	if (x==3)
	{
		cout<<a[0]<<" "<<a[2]<<endl;
		cout<<a[0]<<endl;
		cout<<a[0]<<" "<<a[1]<<endl;
		return;
	}
	if (x>3)
	{
		if (2*a[1]<a[0]+a[x-2])
		{
			cout<<a[0]<<" "<<a[1]<<endl;
			cout<<a[0]<<endl;
			cout<<a[x-2]<<" "<<a[x-1]<<endl;
			cout<<a[1]<<endl;
		}
		else 
		{
			cout<<a[0]<<" "<<a[x-1]<<endl;
			cout<<a[0]<<endl;
			cout<<a[0]<<" "<<a[x-2]<<endl;
			cout<<a[0]<<endl;
		}
	}
	ff(x-2);
}
int main()
{
	int T,n,i;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (i=0;i<n;i++)
			scanf("%d",&a[i]);
		sort(a,a+n);
		printf("%d\n",time(n));
		ff(n);
		if (T) cout<<endl;
	}
	return 0;
}
