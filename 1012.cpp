#include <stdio.h>
int main()
{
	printf("n e\n");
	printf("- -----------\n");
	printf("0 1\n1 2\n2 2.5\n");
	double s=2.5;
	long long f=2;;
	for (int i=3;i<=9;i++)
	{
		f*=i;
		s+=1*1.0/f;
		printf("%d %0.9lf\n",i,s);
	}
	return 0;
}

