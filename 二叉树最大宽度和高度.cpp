#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int x,y;
int a[100][3];
int f[100];
void DFS(int i,int k)
{
	f[k]+=1;
	if (k>x) x=k;
	if (a[i][1]) DFS(a[i][1],k+1);
	if (a[i][2]) DFS(a[i][2],k+1);
	return;
}
int main()
{
	int n,i;
	while (~scanf("%d",&n))
	{
		memset(a,0,sizeof(a));
		memset(f,0,sizeof(f));
		x=0;
		for (i=1;i<=n;i++)
			scanf("%d%d",&a[i][1],&a[i][2]);
		DFS(1,1);
		y=0;
		for (i=1;i<=20;i++)
			if (f[i]>y) y=f[i];
		printf("%d %d\n",y,x);
	}
	return 0;
}
