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
	int n,x,i;
	while (~scanf("%d%d",&n,&x))
	{
		int s=0,a;
		for (i=1;i<=n;i++)
		{
			scanf("%d",&a);
			s+=a;
		}
		if (s<0) s=0-s;
		if (s==0) printf("0\n");
		else
		if (s<=x) printf("1\n");
		else 
		if (s % x==0) printf("%d\n",s/x);
		else printf("%d\n",s/x+1);
	}
	return 0;
}
