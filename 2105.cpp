#include<stdio.h>
int main()
{
	double x,y,x1,y1,x2,y2,x3,y3;
	int n;
	while (scanf("%d",&n)&&n!=0)
	{
		while (n--)
		{
			scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3);
			x=(x1+x2+x3)*1.00/3.00;
			y=(y1+y2+y3)*1.00/3.00;
			printf("%.1lf %.1lf\n",x,y);
		}
	}
	return 0;
}
