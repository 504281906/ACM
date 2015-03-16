#include <stdio.h>
int main()
{
 	int i,n,s;
 	char a[1001];
 	while (scanf("%s",a) && a[0]!='0')
 	{
	 	  s=0;
	 	  for(i=0;a[i]!='\0';i++)
		{
			s+=a[i]-'0';
		}
           while (s>=10)
		    s=s/10+s%10; 
		   printf("%d\n",s);
    }
    return 0;
}
