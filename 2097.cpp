#include <stdio.h>
int f(int s,int a)
{
	int t;
	t=0;
	while (s)
	{
		t+=s%a;
		s=s/a;
	}
	return t;
}
int main()
{
	int f(int,int);
	int s,s1,s2,s3,n;
	while (scanf("%d",&n) && n)
	{
		s1=f(n,10);
		s2=f(n,16);
		s3=f(n,12);
		if (s1==s2&&s1==s3) printf("%d is a Sky Number.\n",n);
		else printf("%d is not a Sky Number.\n",n);
	}
	return 0;
}
