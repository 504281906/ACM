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
#include <ctime>
#define LL __int64
#define EPS 1e-8
using namespace std;
int pd(int x)
{
	if (x%7==0) return 1;
	while (x)
	{
		if (x%10==7) return 1;
		x/=10;
	}
	return 0;
}
int a[110];
int main()
{
	int n,m,k;
	while (~scanf("%d%d%d",&n,&m,&k) && (n+m+k))
	{
		memset(a,0,sizeof(a));
		int pos=1,ans=1,go=1;
		while (a[m]!=k)
		{
			if (pd(ans)) a[pos]++;
			pos+=go;
			ans++;
			if (pos>n)
			{
				pos=n-1;
				go=-1;
			}
			if (pos<1)
			{
				pos=2;
				go=1;
			}
		}
		cout<<ans-1<<endl;
	}
	return 0;
}
