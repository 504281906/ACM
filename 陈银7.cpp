#include<stdio.h>
#include<string.h>
int main()
{
	int g,i,b,n;
	char a[50];
	scanf("%d",&n);
	getchar();
	for(int m=1;m<=n;m++)
	{
		gets(a);
		g=strlen(a);
		int j=1;
			if((a[0]>=65&&a[0]<=90)||(a[0]>=97&&a[0]<=122)||(a[0]==95))
				j=0;
		i=1;
		while(i<g)
		{
				if((a[i]>=65&&a[i]<=90)||(a[i]>=97&&a[i]<=122)||(a[i]==95)||(a[i]>=48&&a[i]<=57))
					j=0;
				i++;
			printf("3");
		}
				if(j==0)
				printf("no\n");
				else
					printf("yes\n");
	printf("4");}
return 0;}

