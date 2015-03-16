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
	int n,m,k,i;
	scanf("%d%d",&n,&m);
	__int64 s=0;
	for (i=0;i<n*m;i++)
	{
		scanf("%d",&k);
		s+=k;
	}
	printf("%I64d\n",s);
	return 0;
}
