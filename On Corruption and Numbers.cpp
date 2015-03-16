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
void yes()
{
	printf("Yes\n");
}
void no()
{
	printf("No\n");
}
int main()
{
#ifdef DEBUG
	freopen("cin.txt", "r", stdin);
	freopen("cout.txt", "w", stdout);
#endif
	int t,a,n,b;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d%d",&n,&a,&b);
		if ( (n<a)  && (n<b) ) 
		{
			no();
			continue;
		}
		int k=n/a;
		if ((b>=2*a-1) || (a<=n && b>=n) || k*b>=n) yes();
		else no();
	}
	return 0;
}
