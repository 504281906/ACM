#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int a[110];
int main()
{
	int T,n,m,i;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&m);
		for (i=0;i<n;i++)
			scanf("%d",&a[i]);
		sort(a,a+n);
		printf("%d\n",(100-a[0])*(100-a[0]));
	}
	return 0;
}

