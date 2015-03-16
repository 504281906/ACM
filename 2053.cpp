#include <cstdio>
#include <cstring>
int f[100010];
int main()
{
	memset(f,0,sizeof(f));
	for (int i=2;i<=100000;i++)
	{
		int j=1,k=i*j;
		while (k<=100000)
		{
			f[k]++;
			j++;
			k=i*j;
		}
	}
	int n;
	while (~scanf("%d",&n))
	{
		if (f[n] % 2==0)
			printf("1\n");
		else printf("0\n");
	}
	return 0;
}
