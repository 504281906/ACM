#include <stdio.h>
int main()
{
	long long a1,a2,a3,n,i,t,s;
	while (~scanf("%lld%lld%lld%lld",&a1,&a2,&a3,&n))
	{
		if (a3-a2 == a2-a1)
		{
			t=(a3-a2) % 100007;
			s=a1 % 100007;
			//for (i=1;i<n;i++) 
				s+=t*(n-1) % 100007;
		}
		else 
		{
			t=a3/a2;
			s=1;
			for (i=1;i<n;i++)
				s=s*t %100007; 
		}
		
		printf("%lld\n",s);
	}
	return 0;
} 
