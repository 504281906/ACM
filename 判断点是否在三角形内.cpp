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
	printf("�����������ε�������������:\n");
	begin:
		scanf("%lf%lf%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y);
	printf("������Ҫ�жϵĵ�����꣬�������������������ζ��㣬������0 0\n");
	while (~scanf("%lf%lf",&d.x,&d.y))
	{
		if (fabs(d.x)<=EPS && fabs(d.y)<=EPS)
			goto begin;
	}
		
	return 0;
}

