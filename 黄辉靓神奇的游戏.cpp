#include <iostream>
#include <time.h>
#include <cstdio>
#include <cstdlib>
int main()
{
	int m,n;
	srand(time(NULL));
	m=rand()%100;
	printf("你的益达！");
	int k=0;
	while(1)
	{
		k++;
	scanf("%d",&n);
		if (n>100)
			printf("请输入正确范围的数\n");
			else 
			    if (m>n)
					printf("数字小了点\n");
					else
					   if (m<n)
						   printf("数字大了\n");
						   else
						   {
								 printf("恭喜\n");break;}
	if (k>=9)
	{
		printf("超时了！！！\n");
		break;
	}
	}

return 0;
}
