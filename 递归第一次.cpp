#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int f(int n)
{
	if (n>=0) return 5;
	else 
		return (f(n+1)+f(n+2)+1);
}
int main()
{
	int n;
	while (~scanf("%d",&n))
	{
		printf("%d\n",f(n));
	}
	return 0;
}
