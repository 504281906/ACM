#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int ff(int n,int k)
{
	if (n==1) return k;
	if (n & 1) return (ff(3*n+1,k+1));
	else return ff(n/2,k+1);
}
int main()
{
	int T,n;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		printf("%d\n",ff(n,0));
	}
	return 0;
}
