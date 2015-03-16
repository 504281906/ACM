#include <stdio.h>
#include <string.h>
int main()
{
	long t,i,j,k,g,l;
	char s[10000][11],f[11];
	i=0;
	while(gets(s[i]),strcmp(s[i],"")!=0)
	{
		i++;
	}
	while (scanf("%s",f)!=EOF)
	{
		l=strlen(f);g=0;
		for (j=0;j<i;j++)
		{
		 t=1;
		 for (k=0;k<l;k++)
		  if (f[k]!=s[j][k]) 
		   {
				t=0;
				break;
		   } 
		  if (t) g++;
	   }
	   printf("%ld\n",g);
	}
	return 0;
} 
