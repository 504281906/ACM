#include <iostream>
#include <time.h>
#include <cstdio>
#include <cstdlib>
int main()
{
	int m,n;
	srand(time(NULL));
	m=rand()%100;
	printf("�����");
	int k=0;
	while(1)
	{
		k++;
	scanf("%d",&n);
		if (n>100)
			printf("��������ȷ��Χ����\n");
			else 
			    if (m>n)
					printf("����С�˵�\n");
					else
					   if (m<n)
						   printf("���ִ���\n");
						   else
						   {
								 printf("��ϲ\n");break;}
	if (k>=9)
	{
		printf("��ʱ�ˣ�����\n");
		break;
	}
	}

return 0;
}
