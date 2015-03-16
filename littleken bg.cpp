#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
	int v[210],f[210],n,m,i,j;
	while (~scanf("%d%d",&n,&m))
	{
		memset(f,0,sizeof(f));
		for (i=0;i<m;i++)
			scanf("%d",&v[i]);
		for (i=0;i<m;i++)
			for (j=n;j>=v[i];j--)
					f[j]=max(f[j],f[j-v[i]]+v[i]);
		printf("%d\n",f[n]);
	}
	return 0;
}
