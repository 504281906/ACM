#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int a[1000010];
int f(int x)
{
	while (x>0)
	{
		int y=x%10;
		x/=10;
		if (y==4) return 1;
		if (y==2 && (x%10==6)) return 1;
	}
	return 0;
}
int main()
{
	int n,m,i;
	for (i=0;i<=1000000;i++)
		if (f(i)) a[i]=a[i-1];
			else a[i]=a[i-1]+1; 
	while (~scanf("%d%d",&n,&m) && (n+m))
	{
		int t=0;
		cout<<a[m]-a[n-1]<<endl;
	}
	return 0;
}

