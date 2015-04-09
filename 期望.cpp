#include <stdio.h>
#include <math.h>
double f[400010];
double ff(int a,int b)
{
	return (f[a]-f[a-b]-f[b]);
}
int main()
{
	int t=1,n,i;
	double p;
	f[0]=0;
	for (i=1;i<=400000;i++)	
		f[i]=f[i-1]+log((double)i);
	while (~scanf("%d%lf",&n,&p))
	{
		double s=0,p1=log(1-p);
		p=log(p);
		for (i=0;i<=n;i++)
		{ 
     	 	s+=(double)i*(exp(ff(2*n-i,n)+(n+1)*p+(n-i)*p1) 
				+exp(ff(2*n-i,n)+(n+1)*p1+(n-i)*p));
		}
		 printf("Case %d: %.6lf\n",t++,s);    
	}
	return 0;
}
