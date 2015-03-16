#include <stdio.h>
#include <string.h>
int a[410]; 
int s[410];
int main()
{
	int n,m,i,t,T;
	scanf("%d",&T); 
	while (T--)
	{
		scanf("%d%d",&n,&m);
		t=1;
		int max=0;
		memset(s,0,sizeof(s));
		for (i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for (i=n+1;i<=2*n;i++)
			a[i]=a[i-n];
		for (i=1;i<=m;i++)
			s[1]+=a[i];
		for (i=m+1;i<=2*n;i++)
			s[++t]=s[t-1]+a[i]-a[i-m];
		for (i=1;i<=t;i++)
			if (max<s[i])
			max=s[i];
		printf("%d\n",max);
	}
	return 0;
} 
