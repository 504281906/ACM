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
struct node
{
	double x,y;
}a,b,c,d;
int main()
{
	printf("请输入三角形的三个顶点坐标:\n");
	begin:
		scanf("%lf%lf%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y);
	printf("请输入要判断的点的坐标，如若想重新输入三角形顶点，请输入0 0\n");
	while (~scanf("%lf%lf",&d.x,&d.y))
	{
		if (fabs(d.x)<=EPS && fabs(d.y)<=EPS)
			goto begin;
	}
		
	return 0;
}

