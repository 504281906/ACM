#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
	int n,m;
	while (~scanf("%d%d",&n,&m))
	{
		double s=0.0;
		for (int i=1;i<n;i++)
		{
			double pos=((double)i/n)*(n+m);
			s+=fabs(pos - floor(pos+0.5))/(n+m); 
		}
		printf("%0.4lf\n",s*10000);
	}
	return 0;
} 
