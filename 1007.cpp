#include <stdio.h>
#include <algorithm>
#include <math.h>
struct node 
{
	double x,y;
}p[100010];
bool cmp(node a,node b)
{
	if (a.x==b.x)
		return a.y<b.y;
	else 
		return a.x<b.x;
}
double ff(node a,node b)
{
	return sqrt( (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y) );
}
int main()
{
	int n;
	while (~scanf("%d",&n) && n)
	{
		double max=0x7fffffff; 
		for (int i=0;i<n;i++)
			scanf("%lf%lf",&p[i].x,&p[i].y);
		std::sort(p,p+n,cmp);
		//for (int i=0;i<n;i++)
		//	printf("%lf %lf\n",p[i].x,p[i].y);
		for (int i=0;i<n-1;i++)
		{
			double d1=0x7fffffff;
			for (int j=i+1;j<n;j++)
			{
				double d=ff(p[i],p[j]);
				if (d1>d) d1=d;
				else break;
			}
			if (max>d1) max=d1;
		}
		printf("%.2lf\n",max/2);
	}
	return 0;
} 
