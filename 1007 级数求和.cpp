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
		int sn=1;
		n=1;
		while (sn<=k)
		{
			n++;
			sn+=1/n;
		}
		printf("%lld\n",n);
	}
	return 0;
}

