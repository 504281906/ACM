#include <stdio.h>
#include <stdlib.h>  
struct node
{
	long long l,c,p,s;
}a[100010];
int cmp(const void *x,const void *y)
{
	if ((*(node *)x).p==(*(node *)y).p)
		(*(node *)x).s-(*(node *)y).s; 
	return (*(node *)x).p-(*(node *)y).p;
}
int main()
{
	long long t,n,m,i;
	scanf("%lld",&t);
	while (t--)
	{
		scanf("%lld%lld",&n,&m);
		long long min=0;
		for (i=0;i<n;i++)
		{
			scanf("%lld%lld%lld",&a[i].l,&a[i].c,&a[i].p);
			a[i].s=a[i].l*a[i].c;
			min+=a[i].s;
		}
		int f=1;
		for (i=0;i<n;i++)
			if (a[i].s>m)
			{
				f=0;
				printf("Impossible\n");
				break;
			}
		if (f)
		{
			qsort(a,n,sizeof(a[0]),cmp);
			long long k=0;
			long long max=0;
			for (i=0;i<n;i++)
			{
				if (min<=m) 
				{
					max+=(min-k)*a[i].p;
					break; 
				}
				max+=(m-k)*a[i].p;
				min-=a[i].s;
				k=m-a[i].s;
			}
			printf("%lld\n",max); 
		}
	}
	return 0;
}
