#include <stdio.h>
#include <string.h> 
int main()
{
	int i,n,j; 
	long long a[25],f[10010];
	for (i=1;i<=21;i++)
		a[i]=i*i*i;
	memset(f,0,sizeof(f));
	f[0]=1;
	for (i=1;i<=21;i++)
		for (j=0;j<=10000-a[i];j++)
			if(f[j]) f[j+a[i]]+=f[j]; 
	while (~scanf("%d",&n))
		printf("%lld\n",f[n]);
	return 0;
}
