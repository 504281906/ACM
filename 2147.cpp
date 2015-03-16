#include <cstdio>
using namespace std;
int main()
{
	int n,m;
	while (~scanf("%d%d",&n,&m) && (n+m))
	{
		if (n % 2==1 && m % 2==1)
		printf("%What a pity!\n");	
		else 
		printf("Wonderful!\n");
	}
	return 0;
}
