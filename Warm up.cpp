#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int fa[200010];
int find(int x)
{
	if (fa[x]!=x) fa[x]=find(fa[x]);
	return fa[x];
}
int main()
{
	int n,m;
	while (~scanf("%d%d",&n,&m) && (n+m))
	{
		for (int i=1;i<=n;i++)
			fa[i]=i;
		for (int i=1;i<=m;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			a=fa[a];b=fa[b]; 
			if (a!=b)
			{
				if (a>b)
				{
					a=a+b;
					b=a-b;
					a=a-b;
				}
				fa[b]=a;
			}
		}
		sort(fa+1,fa+n+1);
		int s=fa[1],t=0;;
		for (int i=2;i<=n;i++)
		{
			if (s!=fa[i])
			{
				s=fa[i];
				t++;
			}
		}
		printf("%d\n",t);
	}
	return 0;
}
