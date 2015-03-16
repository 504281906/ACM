#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int f[30010];
int find(int n)
{
	return (f[n]==n?n:f[n]=find(f[n]));
}
int main()
{
	int n,m,t,i;
	while (~scanf("%d%d",&n,&m) && (n+m))
	{
		int k;
		for (i=0;i<n;i++)
			f[i]=i;
		while (m--)
		{
			scanf("%d",&t);
			scanf("%d",&k);
			k=find(k);
			for (i=1;i<t;i++)
			{
				int a;
				scanf("%d",&a);
				a=find(a);
				f[a]=k;
			}
		}
		k=find(0);
		int s=0;
		for (i=0;i<n;i++)
			if (k==find(i)) s++;
		cout<<s<<endl;
	}
	return 0;
}
