#include <cstdio>
int main()
{
	int n,m;
	int a[110];
	while (~scanf("%d",&n) && n)
	{
		int s=0;
		int t=0;
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			s^=a[i];
		}
		if (s==0) printf("0\n");
		else
		{ 
		for (int i=1;i<=n;i++)
		{
			if (a[i]>(s ^ a[i])) t++;
		}
		printf("%d\n",t);
		}
	}
	return 0;
}
