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
#define eps 1e-8
using namespace std;
int main()
{
    int be = clock();
    int a = 2;
	for(int i = 1;i <= 1000000000 ;i ++)
	{
		 a *= 2 ;
		 a %= 1000000000;
	}
	int en = clock();
	printf("%ld",en - be);
	return 0;
}

