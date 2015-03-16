#include <stdio.h>
#include <map>
#include <vector>
using namespace std;
int main()
{
	int n,m,i,j,k,v;
	map< int,vector<int> >a;
	while(~scanf("%d%d",&n,&m))
	{
		a.clear();
		for (i=1;i<=n;i++)
		{
			scanf("%d",&j);
			a[j].push_back(i);
		}
		for (i=1;i<=m;i++)
		{
			scanf("%d%d",&k,&v);
			if (a[v].size()<k)
				printf("0\n");
			else 
				printf("%d\n",a[v][k-1]);
		}
	} 
	return 0;
} 
