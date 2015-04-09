#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int vis[100010],n,a[100010];
void DFS(int k)
{
	if (k==(n+1))
	{
		for (int i=1;i<=n;i++)
			printf("%d ",a[i]);
		cout<<endl;
		return;
	}
	for (int i=1;i<=n;i++)
		if (vis[i]==0)
		{
			a[k]=i;
			vis[i]=1;
			DFS(k+1);
			vis[i]=0;
		}
	return;
}
int main()
{
	while (~scanf("%d",&n))
	{
		memset(vis,0,sizeof(vis));
		DFS(1);
	}
}
