#include <cstdio>
int main()
{
	int n;
	while (~scanf("%d",&n))
	{
		int f=0;
		for (int i=3;i<=n/2;i++)
			if (n % i==0)
			{
				f=i;
				break;
			}
		if (f) printf("%d\n",f-1);
		else printf("%d\n",n-1);
	}
	return 0;
}
