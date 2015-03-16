#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int gcd(int a,int b)
{
	if (b==0) return a;
	else return gcd(b,a%b);
}
int main()
{
	int T,n,i;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		int ans=0;
		for (i=n/2;i>0;i--)
		{
			int j=n-i;
			if (ans>i*j/gcd(i,j)) break;
			ans=i*j/gcd(i,j);
		}
		printf("%d\n",ans);
	}
	return 0;
}

