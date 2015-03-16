#include <stdio.h>
#include <math.h>
#define P 3.1415926
#define g 9.8
int main()
{
	double v[210],h,x,y,x1,y1;
	int n;
	while (~scanf("%d",&n) && n)
	{
		int max=0;
		scanf("%lf%lf%lf%lf%lf",&h,&x,&y,&x1,&y1);
		for (int i=1;i<=n;i++)
			scanf("%lf",&v[i]);
		double pos = P/1000;
		for (double i=-P/2;i<=P/2;i+=pos)
		{
			int t=0;
			for (int j=1;j<=n;j++)
			{
				double v1=v[j]*cos(i);
				double t1=v[j]*sin(i)/g;
				double t2=sqrt(t1*t1+2*h/g);
				double s=v1*(t1+t2);
				if (s>=x1 && s<=y1)
				{
					t=0;
					break;
				}
				if (s>=x && s<=y) t++;
			}
			if (max<t) max=t;
		}
		printf("%d\n",max);
	}
	return 0;
}
