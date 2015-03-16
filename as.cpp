#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
using namespace std;
int f(int x)
{
    int b , t , c , m , r;
    b = x & -x;
    t = x + b;
    c = t ^ x;
    m = (c >> 2) / b;
    r = t | m; //×îÖÕ½á¹û
    return r;
}
int main()
{
	int n;
	while (~scanf("%d",&n))
	{
		printf("%d\n",f(n));
	}
}
