#include <stdio.h>
#include <string.h>
int main()
{
   int i,k;
   char s[101];
   while (scanf("%s",&s)!=EOF)
   {
         k=0;
         for (i=0;s[i]!='\0';i++)
            if (s[i]>s[k])
              k=i;
         for (i=0;s[i]!='\0';i++)
          {
            printf("%c",s[i]);
            if (s[i]==s[k]) 
              printf("(max)");                
          }
          printf("\n");
   }
   return 0;   
}
