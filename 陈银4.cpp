#include<stdio.h>
#include<string.h>
int main()
{
	         char a[100];
			 int i,g;
			 while (gets(a)!=NULL)
			 {
				 a[0]=a[0]-'a'+'A';
				  
				 g=strlen(a);
				 for(i=1;i<g;i++){
				 if(a[i-1]==' ' && a[i]!=' ')
					 a[i]=a[i]-'a'+'A';}
				 printf("%s\n",a);
				}
			 return 0;
}

