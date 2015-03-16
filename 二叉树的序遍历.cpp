#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int a[20][3];
void zhong(int k)
{
	printf("%d ",k);
	if (a[k][1]) zhong(a[k][1]);
	if (a[k][2]) zhong(a[k][2]);
}
void zuo(int k)
{
	if (a[k][1]) zuo(a[k][1]);
	printf("%d ",k);
	if (a[k][2]) zuo(a[k][2]);
}
void you(int k)
{
	if (a[k][1]) you(a[k][1]);
	if (a[k][2]) you(a[k][2]);
	printf("%d ",k);
}
int main()
{
	int n;
	while (~scanf("%d",&n))
	{
		for (int i=1;i<=n;i++)
			scanf("%d%d",&a[i][1],&a[i][2]);
		zhong(1);
		printf("\n");
		zuo(1);
		printf("\n");
		you(1);
		printf("\n");
	}
	return 0;
}

