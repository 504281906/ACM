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
struct node
{
	int x,y;
}a[100010];
int vis[10010];
int main()
{
	int i;
	memset(vis,0,sizeof(0));
	freopen("out.txt","w",stdout);
	int t=0;
	for (i=1;i<=1000;i++)
		if (!vis[i])
		{
			a[t].x=i;
			a[t].y=i-a[t-1].x+1+a[t-1].y;
			vis[a[t].x]=1;
			vis[a[t].y]=1;
			t++;
		}
	for (i=0;i<t;i++)
		printf("%d %d\n",a[i].x,a[i].y);
	return 0;
}

