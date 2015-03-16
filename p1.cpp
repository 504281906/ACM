#include <stdio.h>
int main()
{ 
	__int64 n,i,m,k;
	double s;
	while (scanf("%I64d%I64d",&n,&m)!=EOF)
	{
		s=1.000;k=n;
		for (i=1;i<m;i++)
		{
			s*=(k-1)*1.000/k;
			k--;
		}
		printf("%.2lf\n",s/(n-m+1));
	}
	return 0;
}
