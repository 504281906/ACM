#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
	double n;
	while (scanf("%lf",&n))
	{
		cout<<acos(n)*180/3.1415926<<endl;
	}
	return 0;
}

