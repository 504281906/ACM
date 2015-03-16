#include <stdio.h>
#include <string.h>
int main()
{
	int i,l,z,f,n,j;
	char s[1000];
	scanf("%d",&n);
	getchar();
    while (n--)
    {
		scanf("%s",&s);
		l=strlen(s);
		z=0;f=1;
		if (s[0]=='-')
		{
		  printf("-");
		  for (i=l-1;i>=1;i--)
		  {
				if (s[i]=='0'&&f==1)
		  		{
					z++;
					continue;	
		 		}
		  f=0;
		  printf("%d",s[i]-'0');
		  }
		  for (i=1;i<=z;i++)
		  printf("0");
		  printf("\n");
		}
		else 
		{
		   	for (i=l-1;i>=0;i--)
			   {
					if (s[i]=='0'&&f==1)
		  	   		{
						z++;
						continue;	
		 			}
		  		f=0;
		  		printf("%d",s[i]-'0');
		 		 }
		 		 for (i=1;i<=z;i++)
		 		 printf("0");
		 	 printf("\n");
		}	
	}
	return 0;
}
