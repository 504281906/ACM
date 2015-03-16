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
	int aa,bb,a,b,c;   
	while (~scanf("%d%d%d",&a,&b,&c)) //ax+by=c?
	{
		/*if (a<b)
		{
			a=a+b;
			b=a-b;
			a=a-b;
		}*/
		exgcd(a,b);
		if (c % q!=0)
		{
			cout<<"没有整数解"<<endl;
			continue;
		}
		int r=b / q;
		int xx=(x*c/q%r+r)%r;
		int yy=(c-a*xx)/b;
		if (yy<0)
		{
			cout<<"没有正整数解"<<endl;
			continue;
		}
		printf("%d = %d * %d + %d * %d\n",c,xx,a,yy,b);
	}
}
