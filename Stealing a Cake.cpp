#include <iostream>
#include <stdio.h>
#include <math.h>
#define EPS 1e-15
using namespace std;

double xx0, yy0;
double x1, yy1, r;
double x2, y2, x3, y3;
double xx2, yy2;

double que1 (double x, double y, int tag)
{
	if (tag) 
		return (pow ((x - x1), 2) + pow ((y - yy1), 2));
	else return (pow ((y - x1), 2) + pow ((x - yy1), 2));
}

double que2 (double x)
{
	double y = sqrt (r*r - (x - x1) * (x - x1));
//	cout << "y = " << yy1 - y << endl;
	double ans1 = sqrt(pow ((xx2 - x), 2) + (pow (yy2 - (yy1 - y), 2))) + sqrt (pow((xx0 - x), 2)+pow((yy0 - (yy1 - y)),2));
	double ans2 = sqrt(pow ((xx2 - x), 2) + (pow (yy2 - (yy1 + y), 2))) + sqrt (pow((xx0 - x), 2)+pow((yy0 - (yy1 + y)),2));
	return ans1 > ans2 ? ans2 : ans1;
}

double three1(double a, double b, double tmp, int tag)
{
	double left, right, mid, midmid, mid_value, midmid_value;
	left = a, right = b;
//	cout << "left = " << left << "right = " << right << endl;
	while (left + EPS < right)
	{
		mid = (left + right)/2;
		midmid = (right + mid)/2;
		mid_value = que1 (mid, tmp, tag);
		midmid_value = que1 (midmid, tmp, tag);
//			cout << "left = " << mid << "right = " << midmid << endl;
		if (mid_value < midmid_value)
			right = midmid;
		else left = mid;
	}
//	cout << "left = " << left<< endl;
	return left;
}

double three2 ()
{
	double left, right, mid, midmid, mid_value, midmid_value;
	left = x1 - r;
	right = x1 + r;
	//cout << "left = " << left << "right = " << right << endl;
	while (left + EPS < right)
	{
		mid = (left + right)/2;
		midmid = (right + mid)/2;
		mid_value = que2 (mid);
		midmid_value = que2 (midmid);
		if (mid_value < midmid_value)
			right = midmid;
		else left = mid;
	}
	return (que2 (left));
}

int main()
{
	double Max;
	while (~scanf ("%lf%lf", &xx0, &yy0) && (xx0 + yy0))
	{
		scanf ("%lf%lf%lf", &x1, &yy1, &r);
		scanf ("%lf%lf%lf%lf", &x2, &y2, &x3, &y3);
		double a, b;
		a = x2 > x3 ? x3 : x2;
		b = x2 > x3 ? x2 : x3;
		Max = 0x7fffffff;
		double tmp = three1(a, b, y2, 1);
		if (Max > que1 (tmp, y2, 1))
		{
			Max = que1 (tmp, y2, 1);
			xx2 = tmp;
			yy2 = y2;
		}
		tmp = three1 (a, b, y3, 1);
		if (Max > que1 (tmp, y3, 1))
		{
			Max = que1 (tmp, y3, 1);
			xx2 = tmp;
			yy2 = y3;
		}
		a = y2 > y3 ? y3 : y2;
		b = y2 > y3 ? y2 : y3;
		tmp = three1 (a, b, x2, 0);
		if (Max > que1 (tmp, x2, 0))
		{
			Max = que1 (tmp, x2, 0);
			xx2 = x2;
			yy2 = tmp;
		}
		tmp = three1 (a, b, x3, 0);
		if (Max > que1 (tmp, x3, 0))
		{
			Max = que1 (tmp, x3, 0);
			xx2 = x3;
			yy2 = tmp;
		}
	//	cout << xx2 <<" " << yy2<<endl;
		printf ("%.2lf\n",three2 ());
	}
	return 0;
}
