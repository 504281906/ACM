#include <stdio.h>
#include <string.h>
int main()
{
    int i,j;
    char s[101];
    while (gets(s)!=NULL)
    {
          s[0]=s[0]-32;
          printf("%c",s[0]);
          for (i=1;s[i]!='\0';i++)
          {
              printf("%c",s[i]);
              if (s[i]==' ') 
              s[i+1]=s[i+1]-32;
          }
          printf("\n");
    }
    return 0;
}
