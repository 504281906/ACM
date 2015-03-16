#include <cmath>
#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	double n;
	while (~scanf("%lf",&n))
	{
		int f=floor(n);
		int f1=ceil(n);
		printf("floor: %d\n",f);
		printf("ceil: %d\n",f1);
	}
	return 0;
}
