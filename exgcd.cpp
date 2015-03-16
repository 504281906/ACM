#include <iostream>
using namespace std;
int x,y,q;
int exgcd(int a,int b)
{
	if (b==0)
	{
		x=1;
		y=0;
		q=a;
		return 0;
	}
	else
	{
		exgcd(b,a%b);
		int t=x;
		x=y;
		y=t-a/b*y;
	}
	return 0;
}
int main()
{
	int a,b;
	while (~scanf("%d%d",&a,&b))
	{
		if (a<b)
		{
			a=a+b;
			b=a-b;
			a=a-b;
		}
		exgcd(a,b);
		printf("%d = %d * %d + %d * %d\n",q,x,a,y,b);
	}
}
