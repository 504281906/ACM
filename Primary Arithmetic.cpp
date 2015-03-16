#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
	long long n,m;
	while (~scanf("%lld%lld",&n,&m) && (n+m))
	{
		int k=0,t=0;
		while ((n+m))
		{
			k=(n % 10)+(m % 10)+k;
			n/=10;
			m/=10;
			if (k>=10)
			{
				t++;
				k=1;
			}
			else k=0;
		}
		if (t==0) printf("No carry operation.\n");
		else if (t==1) printf("1 carry operation.\n");
		else printf("%d carry operations.\n",t);
	}
	return 0;
}

