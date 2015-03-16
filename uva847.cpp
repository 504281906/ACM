#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std; 
void ff(double x,bool f)
{
	if (x<=9 && f)
	{
		printf("Stan wins.\n");
		return;
	}
	if (x<=2 && !f)
	{
		printf("Ollie wins.\n");
		return;
	}
	if (f)
		ff(ceil(x/9),!f);
	else 
		ff(ceil(x/2),!f);
}
int main()
{
	long long n;
	while (~scanf("%lld",&n))
	{
		ff(n,true);
	}
}
