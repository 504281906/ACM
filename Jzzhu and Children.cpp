#include <bits/stdc++.h>
using namespace std;
int b[110];
double a[110];
int main()
{
	int n,m,i;
	scanf("%d%d",&n,&m);
	int max=-1,pos;
	for (i=1;i<=n;i++)
	{
		scanf("%lf",&a[i]);
		b[i]=ceil(a[i]/m);
		if (max<=b[i]) 
		{
			max=b[i];
			pos=i;
		}
	}
	printf("%d\n",pos);
	return 0;
}
