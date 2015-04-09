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
using namespace std;
//#define DEBUG
int main()
{
#ifdef DEBUG
	freopen("cin.txt", "r", stdin);
	freopen("cout.txt", "w", stdout);
#endif
	__int64 n;
	while (~scanf("%I64d",&n))
	{
		
		__int64 s;
		if (n<3) 
		{
			printf("%I64d\n",n);
			continue;
		}
		if (n%2==1)
			s=n*(n-1)*(n-2);
		else
		{
			if (n%3==0)
				s=(n-3)*(n-1)*(n-2);
			else
				s=n*(n-1)*(n-3);		
		}
		printf("%I64d\n",s);
	}
	return 0;
}
