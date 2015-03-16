#include <cstdio>
#include <cstring>
#include <cmath>
int f[3010];
int a[3010];
int main()
{
	int n;
	while (~scanf("%d",&n))
	{
		memset(f,0,sizeof(f));
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if (i!=1)
			{
			int k=fabs(a[i]-a[i-1]);
			f[k]=1;
			}
		}
		int t=1;
		for (int i=1;i<n;i++)
		if (f[i]==0) 
		{
			t=0;
			printf("Not jolly\n");
			break;
		}
		if (t) printf("Jolly\n");
	} 
	return 0;
}
