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
#define LL __int64
int a[1000010];
char c[20];
int main()
{
	int n,m;
	memset(a,0,sizeof(a));
	for (int i=1;i<=1000000;i++)
	{
		sprintf(c,"%d",i);
		if (strstr(c,"4") || strstr(c,"62"))
			a[i]=a[i-1];
		else a[i]=a[i-1]+1;
	}
	while (~scanf("%d%d",&n,&m) && (n+m))
		cout<<a[m]-a[n-1]<<endl;
	return 0;
}
