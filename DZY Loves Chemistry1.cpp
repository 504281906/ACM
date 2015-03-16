#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int f[1000];
int c[550];
int find(int a)
{
	if (a!=f[a]) f[a]=find(f[a]);
	return f[a];
}
int main()
{
	int n,m,i,j,a,b;
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++)
		f[i]=i;
	for (i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		a=find(a);
		b=find(b); 
		f[a]=b;
	}
	memset(c,0,sizeof(c));
	for (i=1;i<=n;i++)
	{
		int d=find(i);
		c[d]++;
	}
	int max=0;
	__int64 h=1;
	for (i=1;i<=n;i++)
	if (c[i]!=1)
	for (j=1;j<c[i];j++)
		h*=2;
	printf("%I64d\n",h);
	return 0;
}
