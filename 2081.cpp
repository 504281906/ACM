#include <stdio.h>
#include <string.h>

int main () {
	int n, i;
	char a[11];
	scanf("%d", &n);
	getchar();
	while(n--)
	{
		for(i =0;i<6;++i)
		getchar();
		gets(a);
		printf("6%s\n",a);
	}
	return 0;
}
