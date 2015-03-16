#include <stdio.h>
int main()
{
	int t,s,n,i;
	int a[4];
	scanf("%d",&t);
	while (t--)
	{
		s=0;
		scanf("%d",&n);
		a[1]=n/2;
		a[2]=(n-a[1])*2/3;
		a[3]=n-a[1]-a[2];
		for (i=1;i<=3;i++)
		 {
			if (a[i]%10==0) s+=a[i]/10;
			else s+=a[i]/10+1;
		 }
		printf("%d\n",s);
	}
	return 0;
}
