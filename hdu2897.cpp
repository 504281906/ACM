#include <cstdio>
int main()
{
	int n,a,b;
	while (scanf("%d%d%d",&n,&a,&b)==3)
	{
		n=n%(a+b);
		if (n<=a && n!=0) printf("LOST\n");
		else printf("WIN\n"); 
	}
	return 0;
}
