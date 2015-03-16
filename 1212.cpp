#include <stdio.h>
#include <string.h>
int main()
{
	char a[100000];
	int b,s,i,l;
	while (scanf("%s%d",&a,&b)!=EOF)
	{
		l=strlen(a);s=0;
		for (i=0;i<l;i++)
		 s=(s*10+a[i]-'0')%b;
		printf("%d\n",s);
	}
	return 0;
}
