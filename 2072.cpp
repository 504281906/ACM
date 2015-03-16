#include <stdio.h>
#include <string.h>
int main()
{
    int m,n,i,j,max;
    char s[100];
    char a[100][100];
    while (gets(s)!=NULL && s[0]!='#')
    {
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
       max=m;
       for (i=0;i<m;i++)
        for (j=i+1;j<m;j++)
         if (strcmp(a[i],a[j])==0) 
          {
            max--;
            break;
          }
    printf("%d\n",max);
    }
    return 0;
}
