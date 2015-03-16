#include <iostream>
using namespace std;
int gcd(int a,int b)
{
	if (a%b) gcd(b,a%b);
		else return b;
}
int main()
{
	int n,m;
	while (~scanf("%d%d",&n,&m))
	{
		int k=gcd(n,m);
		printf("%d\n",n*m/k);
	}
	return 0;
} 
