#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int k; 
char s[100]={"`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./"};
int find(char c)
{
	for (int i=0;i<k;i++)
	if (c==s[i]) return i;
}
int main()
{
	char s1[100];
	k=strlen(s);
	while (gets(s1)!=NULL)
	{
		int l=strlen(s1);
		for (int i=0;i<l;i++)
		if (s1[i]==' ') printf(" ");
		else 
		{
			int x=find(s1[i]);
			printf("%c",s[x-1]);
		}
		printf("\n");
	}
	return 0;
}
