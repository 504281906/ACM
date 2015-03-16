#include <stdio.h>
#include <string.h>
#define M 1000005
int a[M],f[M],s[M],jl[M];
__int64 d[M];
int main()
{
	int n,m,t;
	while (~scanf("%d",&n)&&n)
	{
		memset(jl,0,sizeof(jl));
		memset(f,0,sizeof(f));
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			jl[i-f[a[i]]]++;
			f[a[i]]=i;
		}
		memset(f,0,sizeof(f));
		s[1]=1;
		f[a[n]]=1;
		for (int i=2;i<=n;i++)
		{
			if (f[a[n-i+1]]==0)
			{
				f[a[n-i+1]]=1;
				s[i]=s[i-1]+1;
			} 
			else s[i]=s[i-1];
		}
		d[1]=n;
		int k=n;
		for (int i=2;i<=n;i++)
		{
			d[i]=d[i-1]-s[i-1];
			k-=jl[i-1];
			d[i]+=k;
		}
		scanf("%d",&t);
		while (t--)
		{
			scanf("%d",&m);
			printf("%I64d\n",d[m]);
		}
	}
	return 0;
}
