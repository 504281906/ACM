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
	int T;
	double x1,x2,x3,r1,r2,r,y1,y2,y3;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&x1,&y1,&r1,&x2,&y2,&r2,&x3,&y3);
		r=(r1*r1-r1-r2*r2+r2)/(2*(r2-r1));
		printf("%lf\n",r);
	}
	return 0;
}
