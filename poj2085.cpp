#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n,m,i;
	while (scanf("%d%d",&n,&m)==2 && (n+m!=-2))
	{
		int p=1;
		while (p*(p-1)/2<m) p++;
		int t=p*(p-1)/2;
		for (i=1;i<=n-p;i++)
			printf("%d ",i);
		printf("%d ",n-t+m);
		for (i=n;i>=n-p+1;i--)
			if (i!=n-t+m)
				printf("%d ",i);
		cout<<endl;
	}
	return 0;
}
