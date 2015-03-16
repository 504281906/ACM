#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int su(int n)
{
	int i;
	for (i=2;i<=sqrt(n);i++)
		if (n % i==0) return 0;
	return 1;
}
int main()
{
	int n,i;
	while (~scanf("%d",&n) && n)
	{
		int t=0;
		for (i=3;i<=n/2;i+=2)
			if (su(i) && su(n-i)) t++;
		cout<<t<<endl;
	}
	return 0;
}

