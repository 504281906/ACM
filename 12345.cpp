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
#define LL __int64
#define EPS 1e-8
using namespace std;
int main()
{
	int x1,x2,x3,x4,y1,y2,y3,y4,k;
	scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
	if (x1==x2)
	{
		k=y2-y1;
		printf("%d %d %d %d\n",x1+k,y1,x2+k,y2);
	}
	else if (y1==y2)
	{
		k=x1-x2;
		printf("%d %d %d %d\n",x1,y1+k,x2,y2+k);
	}
	else if (abs(x2-x1)==abs(y2-y1))
	{
		printf("%d %d %d %d\n",x3,y4,x4,y3);
	}
	else puts("-1");
	return 0;
}

