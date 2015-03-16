#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
#include <map>
#include <stack>
#include <list>
#include <vector>
using namespace std;
//#define DEBUG
int main()
{
#ifdef DEBUG
	freopen("cin.txt", "r", stdin);
	freopen("cout.txt", "w", stdout);
#endif
	int f[110],n,a,b,l,r,i;
	memset(f,0,sizeof(f));
	scanf("%d",&n);
	scanf("%d%d",&a,&b);
	n--;
	while (n--)
	{
		scanf("%d%d",&l,&r);
		for (i=l;i<r;i++)
			f[i]=1;
	}
	int t=0;
	for (i=a;i<b;i++)
		if (f[i]==0) t++;
	printf("%d\n",t);
	return 0;
}
