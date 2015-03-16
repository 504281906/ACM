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
#define LL __int64
#define EPS 1e-8
using namespace std;
int a[10000010],s[10000010];
int main()
{
	a[0]=1;
	s[0]=1;
	for (int i=1;;i++)
	{
		a[i]=a[i-1]+i*4;
		s[i]=s[i-1]+a[i];
		if (s[i]>1000000000) break;
	}
	int n;
	while (~scanf("%d",&n))
	{
		int i;
		for (i=1;;i++)
			if (s[i]>n)
				break;
		cout<<i<<endl;
	}
	return 0;
}
