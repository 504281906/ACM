#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	char s[100];
	printf("黄辉靓是只猪？请输入yes或no:");
	//getchar();
	scanf("%s",&s);
	while(1)
	{
	if (strcmp(s,"yes")==0)
		{
			printf("恭喜你答对了！");
			break;
		}
	else 
		{
			printf("请重新输入：");
			scanf("%s",&s);
		}
	}
	return 0;
}
