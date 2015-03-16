#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	long long a,b,t,k,c;
	char s[1001],s1[1001];
	scanf("%lld",&t);
	getchar();
	while (t--)
	{
		gets(s);
		a=atoi(s);
		for (int l = 0, r = strlen(s) - 1; l < r; l++, r--)
     	{
		char t = s[l];
			s[l] = s[r];
			s[r] = t;
		}
		b=atoi(s);
		k=0;
		while (a!=b)
		{
			k++;
			a+=b;
			b=0;
			c=a;
			while (c)
			{
				b=b*10+c%10;
				c/=10;
			}
		}
		printf("%lld %lld\n",k,a);
	}
	return 0;
}
