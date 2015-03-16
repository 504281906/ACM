#include <stdio.h>
#define max 30001
int main()
{
	int i,j,t,n,s;
	int a[1000];
	while (scanf("%d",&n)!=EOF)
	{
		t=0;
		for (i=1;i<=n;i++)
		scanf("%d",&a[i]);
		for (i=1;i<=n;i++)
		 {
			if (a[i]!=max)
			{
				t++;
				s=a[i];
			}
		 for (j=i;j<=n;j++)
		    if (s>=a[j])
		    {
				s=a[j];
				a[j]=max;
			}
		 }
		printf("%d\n",t);
	}
	return 0;
}
