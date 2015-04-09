#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
	int k;
	long long n;
	while (~scanf("%d",&k))
	{
		double sn=1;
		n=1;
		while (k-sn>=1e-9)
		{
			n++;
			sn=sn+1.0/n;
		}
		printf("%lld\n",n);
	}
	return 0;
}
