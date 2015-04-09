#include<stdio.h>
#include<string.h>
int main()
{
	int n,i,t,j,g;
	char a[100];
	scanf("%d",&n);
	getchar(); 
	for(t=1;t<=n;t++){
		gets(a);
         g=1;
		j=strlen(a);
		for(i=0,j=j-1;i<=j;i++,j--){
			if(a[i]!=a[j])
				g=0;
	}
		if(g==1)
			printf("yes\n");
		else
			printf("no\n");}
	
	return 0;}

