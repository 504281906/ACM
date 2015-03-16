#include <stdio.h>
#include <string.h>
int main()
{
  char s[101];
  int i,k=0,j,n;
  scanf("%d",&n);
  for (i=1;i<=n;i++)
  {
   scanf("%s",&s);
   for(j=0;j<=strlen(s);j++)
	if(s[j]>='0'&& s[j]<='9')
      k++;
	printf("%d\n",k);
	k=0;
   }
return 0;	   
}
