#include <iostream>
using namespace std;
int main()
{
	freopen("A-small-practice.in","r",stdin);
	freopen("output.out","w",stdout);
	int a[5010];
	int n,i,j,p,m,f;
	int t=1;
	scanf("%d",&n);
	while (n--)
	{
		f=1;
		scanf("%d",&p);
		scanf("%d",&m);
		for (i=1;i<=m;i++)
			scanf("%d",&a[i]);
		for (i=1;i<m;i++)
			if (f)
				for (j=i+1;j<=m;j++)
					if (a[i]+a[j]==p)
					{
						f=0;
						printf("Case #%d: %d %d\n",t++,i,j);
						break;
					}
	}
	return 0;
}
