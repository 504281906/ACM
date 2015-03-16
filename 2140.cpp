#include <stdio.h>
#include <string.h>
char f(char a)
{
    switch(a)
    {
        case 'b':return' ';
        case 'q':return',';
        case 't':return'!';
        case 'm':return'l';
        case 'i':return'e';
        case 'c':return'a';
        case 'a':return'c';
        case 'e':return'i';
        case 'l':return'm';
        default:return a;
    }
}
int main()
{
	char s[10001];
	int l,i;
	while (scanf("%s",&s)!=EOF)
    {
		l=strlen(s);
		for (i=0;i<l;i++)
		 printf("%c",f(s[i]));
		printf("\n");
	}
	return 0;
}
