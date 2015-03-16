#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;
const double PI = 3.1415926;
const double g=9.8;
int main()
{
	int n;
	double h,x,y,x1,y1;
	double f[210];
	while (~scanf("%d",&n)&&n)
	{
		int max=0;
		scanf("%lf%lf%lf%lf%lf",&h,&x,&y,&x1,&y1);
		for (int i=1;i<=n;i++)
		scanf("%lf",&f[i]);
		double add = PI/1000; 
		for (double i=-PI/2;i<=PI/2;i+= add)
		{
			int t=0,ff=0;
			for (int j=1;j<=n;j++)
			{
				double s;
				double vy0 = f[j]*sin(i);
				double vx0 = f[j]*cos(i);
				double vy = sqrt(2*h*g + vy0*vy0);
				double r = (vy - vy0)/g;
				s = vx0 * r;
				if (s >= x && s <= y)
				{
					t++;
				}
				if (s >= x1 && s <= y1) 
					{
						t = 0;
						break;
					}
			}
			if (max<t) max=t;
		}
		printf("%d\n",max);
	}
	return 0;
}
