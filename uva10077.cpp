#include <cstdio>
#include <cstring>
struct node
{
	int s,x;
}zuo,you,zhong;
int main()
{
	int n,m;
	while (~scanf("%d%d",&n,&m) && (n!=m))
	{
		zuo.s=0;zuo.x=1;
		zhong.s=1;zhong.x=1;
		you.s=1;you.x=0;
		while (1)
		{
			if (n*zhong.x==m*zhong.s)
				break;
			if (n*zhong.x>m*zhong.s)
			{
				printf("R");
				zuo=zhong;
				zhong.s+=you.s;
				zhong.x+=you.x;
			}
			else
			{
				printf("L");
				you=zhong;
				zhong.s+=zuo.s;
				zhong.x+=zuo.x;
			}
		}
		printf("\n");
	}
	return 0;
}
