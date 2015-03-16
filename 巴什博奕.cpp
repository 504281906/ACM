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
int main()
{
	int n,m;
	while (~scanf("%d%d",&n,&m))
	{
		if (n % (m+1)==0) printf("GG\n");
		else printf("Ê×ÏÈÈ¡%d\n",n % (m+1));
	}
	return 0;
}

