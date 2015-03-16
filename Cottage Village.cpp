#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
double f[2500];
int main()
{
	int n,t,i;
	while (~scanf("%d%d",&n,&t))
	{
		memset(f,0,sizeof(f));
		for (i=1;i<=n;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			f[2*i-1]=a-b*1.0/2;
			f[2*i]=a+b*1.0/2;
		}
		n*=2;
		int ans=2;
		sort(f+1,f+n+1);
		for (i=3;i<n;i+=2)
		{
			if (f[i]-f[i-1]>t) ans+=2;
			if (f[i]-f[i-1]==t) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}

