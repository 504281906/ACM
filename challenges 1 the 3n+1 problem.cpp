#include <cstdio>
#include <cstring>
#include <algorithm>
int f[5000100];
int a[1000100];
int n,m;
int ff(int x)
{
	int k=x,t=1;
	while (k!=1)
	{
		if (k % 2==0)
			k/=2;
		else 
			k=3*k+1;
		t++;	
	}
	return t;
}
int main()
{
	memset(f,0,sizeof(f));
	while (~scanf("%d%d",&n,&m))
	{
		int max=0;
		int n1=n,m1=m;
		if (n>m)
		{
		int t=n;
		n=m;
		m=t;
		}
		for (int i=n;i<=m;i++)
		{
			if (f[i]==0)
			f[i]=ff(i);
			if (f[i]>max)
			max=f[i];
		}
		printf("%d %d %d\n",n1,m1,max);
	}
	return 0;
}
