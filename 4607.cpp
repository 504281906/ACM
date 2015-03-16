#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;
vector <int> f[100010];
int d[100010];
void FBS(int k,int begin,int s)
{
	d[k]=s;
	for (int i=0;i<f[k].size();i++)
	if (f[k][i]!=begin) FBS(f[k][i],k,s+1);
}
int main()
{
	int T; 
	scanf("%d",&T);
	while(T--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for (int i=1;i<n;i++) f[i].clear();
		for (int i=1;i<n;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			f[a].push_back(b);
			f[b].push_back(a);
		}
		int k=1;
		FBS(k,0,0);
		for (int i=2;i<=n;i++) 
		if (d[i]>d[k]) k=i;
		FBS(k,0,0);
		for (int i=1;i<=n;i++)
		if (d[i]>d[k]) k=i;
		k=d[k];
		for (int i=1;i<=m;i++)
		{
			int s;
			scanf("%d",&s);
			if (s<=k+1) printf("%d\n",s-1);
			else printf("%d\n",k+(s-k-1)*2);
		}
	} 
	return 0;
}
