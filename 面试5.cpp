#include<stdio.h>
#include<string.h>
int main()
{
	int i,j,t;
	char a[100];
	while(scanf("%s",a)!=EOF)
	{
		j=strlen(a)-1;
		i=0;
		t=0;
		while(i<j){
			if(a[i]=a[j])
			t++;
			i++;
			j--;
			}
			if(t==i)
			printf("yes\n");
			else
			printf("no\n");
		
		
	}
	return 0;
}
