#include <stdio.h>
int main()
{
	int i,n,s;
	i=0;
	while (scanf("%d",&n)!=EOF)
	{
		s=0;
		while (n>0)
		{
		  if (n%2==0)
			 s+=n%10;
				n=n/10;
		}
		if (i) printf("\n%d\n",s);
		else {
		printf("%d\n",s);
		i=1;}
	}
	return 0;
}
