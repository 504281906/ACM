#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmp(const void *a,const void *b)
{
	return *(int *)b-*(int *)a;
}
int main()
{
	int n,p,i,j;
	int a[1010];
	while (~scanf("%d%d",&n,&p))
	{
		for (i=0;i<n;i++)
			scanf("%d",&a[i]);
		qsort(a,n,sizeof(a[0]),cmp);
		int t=-1;
		int s=0;
		int t1=0;
		int t2=0;
		while (t!=t1)
		{
			t=t1;
			for (i=0;i<n;i++)
			{
				s=0;
				for (j=i;j<n;j++)
				{
					if (a[i]>=a[j] && a[j]!=0)
						s++;
				}
				if (s*a[i]<=p && a[i]!=0)
				{
					t1+=s;
					int f=a[i];
					for (j=i;j<n;j++)
						if (f>=a[j])
							a[j]=0;
					t2++;
				}
				while (a[i]==a[i+1]) i++;
			}
		}
		printf("%d %d\n",t1,t2);
	}
	return 0;
} 
