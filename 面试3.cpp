#include <stdio.h>
#include <string.h>
int main()
{
    int m,n,i,j,max;
    char s[100],s1[100];
    char a[100][100];
    gets(s);
    gets(s1);
    printf("%s",s1);
          m=0;i=0;
          while(s[i]!='\0')
             {
               if(s[i]!=' ')  
               {
                 n=0;
                 for(j=i;s[j]!='\0' && s[j]!=' ';j++,n++)
                    a[m][n]=s[j]; 
                 a[m][n]='\0';
                 m++; 
                 i=j;      
                }
             else
              i++;
            }
            max=0;
       for (i=0;i<m;i++)
         if (strcmp(a[i],s1)==0) 
            max++;
    printf(":%d\n",max);
    return 0;
}
