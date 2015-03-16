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
	int n,m,i;
	int f[4010];
	while (~scanf("%d%d",&n,&m))
	{
		memset(f,0,sizeof(f));
		for (i=1;i<=m;i++)
		{
			int a,c,b;
			scanf("%d",&a);
			if (a==1) 
			{
				scanf("%d%d",&b,&c);
				f[b]=1;f[c]=1;
			}
			else if (a==2)
			{
				scanf("%d",&b);
				f[b]=1;
			}
		}
		int s=0,min=0;
		for (i=1;i<n;i++)
			if (f[i]==0)
			{
				if (f[i+1]==0 && i+1<n)
				{
					f[i+1]=1;
					s++;
				}
				min++;
				s++;
			}
		printf("%d %d\n",min,s);
	}
	return 0;
}
