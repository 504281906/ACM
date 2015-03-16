#include <stdio.h>
int main()
{
	int i,n,s,max,l1,l2,l3;
	int a[10000];
	while (scanf("%d",&n)&& n!=0)
    {
		max=-32767;s=0;l1=1;
		for (i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			s+=a[i];
			if (s>max) 
			{
				max=s;
				l2=l1;
				l3=i;
			}
			if (s<0)
			{
				s=0;
				l1=i+1;
			}
		}
		if (max<0)
		{
			max=0;
			l2=1;
			l3=n;
		}
		printf("%d %d %d\n",max,a[l2],a[l3]);
	}
	return 0;
}
