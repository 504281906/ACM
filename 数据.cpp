#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
#include <map>
#include <stack>
#include <list>
#include <vector>
#include <ctime>
#define LL __int64
#define EPS 1e-8
using namespace std;
int main()
{
	freopen("in.txt","w",stdout);
	srand((LL)time(0));
	int k=100;
	while (k--)
	{
		LL n=1+rand()%10000000000000000;
		printf("%lld\n",n);
	}
	return 0;
}

