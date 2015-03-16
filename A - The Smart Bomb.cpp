#include <stdio.h>
#include <math.h>

double dis(int x1, int y1, int x2, int y2)
{	
	return sqrt((pow((x1-x2), 2) + pow((y1-y2), 2)));
}

int main()
{
	double l1, l2, l3;
	int x1, y1, x2, y2, x3, y3;
	while (~scanf ("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3))
	{
		l1 = dis(x1, y1, x2, y2);
		l2 = dis(x2, y2, x3, y3);
		l3 = dis(x1, y1, x3, y3);
		double r1, r2, r3;
		r1 = 1.*(l1 - l2 + l3)/2;
		r2 = l1 - r1;
		r3 = l2 - r2;
		printf ("%.6lf\n%.6lf\n%.6lf\n", r1, r2, r3);
	}
	return 0;
}
