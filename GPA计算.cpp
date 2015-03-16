#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
	int n,i;
	double a,b;
	scanf("%d",&n);
	double s=0;
	double h=0;
	//char c[100];
	for (i=0;i<n;i++)
	{
		scanf("%lf%lf",&a,&b);
		h+=a;
		s+=a*b;
	}
	printf("%.2lf\n",s*1.000/h);
	return 0;
}
