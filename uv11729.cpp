#include <cstdio>
#include <algorithm>
using namespace std;
struct node
{
	int b,j;
}f[1010];
bool cmp(node a,node b)
{
	return a.j>b.j;
}
int main()
{
	int n;
	int T=1;
	while (~scanf("%d",&n)&& n)
	{
		for (int i=0;i<n;i++)
			scanf("%d%d",&f[i].b,&f[i].j);
		sort(f,f+n,cmp);
		int t=0,s=0;
		for (int i=0;i<n;i++)
		{
			t+=f[i].b;
			if (t+f[i].j>s) s=t+f[i].j;
		}
		printf("Case %d: ",T++);
		printf("%d\n",s);
	} 
	return 0;
} 
