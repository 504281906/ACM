//泊松分布公式P(X=k)=(e^(-p)*p^k)/(k!) p代表当前能获得的期望,k为目标获得的值。
//比如此题外星人1天能生长器官的期望是p,但是要求1天生长器官不超过k。 
//p(x<=k)=p(0)+p(1)+p(2)+p(3)+....p(k) 
#include <stdio.h>
#include <math.h> 
int main()
{
	int t,i,n;
	double m;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%lf",&n,&m);
		double k=1.000;
		double s=exp(-m); 
		for (i=1;i<=n;i++)
		{
			k*=(i*1.000);
			s+=exp(-m)*pow(m,i)/k;
		}
		printf("%0.3lf\n",s);
	}
	return 0;
}
