#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	int a[55];
	int T=0;
	while (~scanf("%d",&n) && n)
	{
		int ans=0;
		int s=0;
		if (T) cout<<endl;
		T++;
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			s+=a[i];
		}
		s/=n;
		for (int i=1;i<=n;i++)
			if (a[i]>s) ans+=a[i]-s;
		cout<<ans<<endl;
	}
	return 0;
}

