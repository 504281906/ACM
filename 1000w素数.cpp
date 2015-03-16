#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int M=1e7+10;
int a[M];
int f[M]; 
int main()
{
	freopen("1千万内的素数.txt","w",stdout);
	int i,j,n;
	memset(a,0,sizeof(a));
	memset(f,0,sizeof(f));
	int t=0;
	for (i=2;i<M;i++)
	{
		if (!a[i])
			f[++t]=i;
		for (j=1;f[j]!=0 && (n=f[j]*i)<M;j++)
		{
			a[n]=1;
			if (i % f[j]==0) break;
		}
	}
	for (i=1;i<=t;i++)
		printf("%d ",f[i]);
	printf("%d\n");
	return 0;
}
