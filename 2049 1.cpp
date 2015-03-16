#include <stdio.h>
#include <stdlib.h>
int main()
{
 	char s[100];
 	int n;
 	while (scanf("%d",&n)!=EOF)
 	{
	 	  itoa(n,s,2);
	 	  printf("%s\n",s);
  	}
  	return 0;
}
