#include <stdio.h>
struct node
{
	long long n,m;
}a[1010];
int main()
{
	int f[1010];
	char s[10]; 
 	int i,j,k;
	scanf("%s",&s);
	int t=1;
	while (s[0]!='#')
	{
		scanf("%d%d",&a[t].n,&a[t].m);
		f[t]=a[t].m;
		t++;
		scanf("%s",&s);
	}
	scanf("%d",&k);
	for (i=1;i<=k;i++)
	{
		int min=0,pos; 
		for (j=1;j<t;j++)
			if ( min==0 || min>a[j].m || (min==a[j].m && a[pos].n>a[j].n))
			{
				min=a[j].m;
				pos=j;
			}
		printf("%lld\n",a[pos].n);
		a[pos].m+=f[pos];
	}
	return 0;
}
