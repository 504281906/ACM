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
int a[100010]; 
int main()
{
#ifdef DEBUG
	freopen("cin.txt", "r", stdin);
	freopen("cout.txt", "w", stdout);
#endif
	int n,m,i,x,y,c;
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++)
		scanf("%d",&a[i]);
	while (m--)
	{
		scanf("%d%d%d",&c,&x,&y);
		switch (c)
		{
			case 1:
			{
				a[x]=y;
				break;
			}
			case 2:
			{
				long long s=0;
				for (i=x;i<=y;i++)
					s+=a[i];
				printf("%lld\n",s);
				break;
			}
			case 3:
			{
				long long s=0;
				for (i=x;i<=y;i++)
					if (s<a[i]) s=a[i];
				printf("%lld\n",s);
				break;
			}
		}
	}
	return 0;
}
