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
int a[1111];
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int n,x,y,i,t1=0,t2=0;
		scanf("%d%d%d",&n,&x,&y);
		for (i=1;i<=n;i++)
			scanf("%d",&a[i]);
		if (a[1]==x) t1=1;
		if (a[n]==y) t2=1;
		if (t1+t2==2) printf("BOTH\n");
		else if (t1+t2==0) printf("OKAY\n");
		else if (t1==1) printf("EASY\n");
		else printf("HARD\n");
	}
	return 0;
}

