#include <cstdio>
int main()
{
	int n,m;
	while (~scanf("%d%d",&n,&m))
	{
		if (n<=m)
		{
			for (int i=n;i<m;i++)
			printf("%d ",i);
			printf("%d\n",m);
		}
		else 
			if (n % (m+1))
			printf("%d\n",n%(m+1));
			else 
			printf("none\n");
	}
	return 0;
}
