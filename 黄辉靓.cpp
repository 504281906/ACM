#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	char s[100];
	printf("�ƻ�����ֻ��������yes��no:");
	//getchar();
	scanf("%s",&s);
	while(1)
	{
	if (strcmp(s,"yes")==0)
		{
			printf("��ϲ�����ˣ�");
			break;
		}
	else 
		{
			printf("���������룺");
			scanf("%s",&s);
		}
	}
	return 0;
}
