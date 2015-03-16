#include <stdio.h>
int main()
{
	long long s,a,b,k1,k2,t; 
	while (scanf("%lld%lld",&a,&b)!=EOF && (a+b))
	{
		t=1;k1=1;k2=2;
		while (t<a)
		{
			t=k1+k2;
			k1=k2;
			k2=t;
		}
		s=0;
		while (t<=b)
		{
			t=k1+k2;
			k1=k2;
			k2=t;
			s++;
		}
		if (a==1) s++;
		printf("%lld %lld\n",s);
	}
	return 0;
}
