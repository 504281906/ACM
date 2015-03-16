#include <cstdio>
#include <cstring>
#include <iostream>
char s[10][10]={"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
int main()
{
	char c[10];
	double l;
	double v;
	while (~scanf("%s%lf%lf",&c,&l,&v))
	{
		int i,k=0;
		for (i=0;i<7;i++)
			if (strcmp(c,s[i])==0)
			{
				k=i;
				break;
			}
		double f=48*v;
		int g=l / f-1;
		l-=g*f;
		while (l>0)
		{
			int g=8;
			if ( (k % 7==5) || (k % 7 ==6) ) g=4;
			k++;
			l-=g*v;
		}
		k--;
		printf("%s\n",s[k % 7]);
	}
	return 0;
}
