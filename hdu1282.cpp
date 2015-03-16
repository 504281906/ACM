#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LL __int64
int main ()
{
    char s1[50],s2[50];
    char out[1010][50];
    int size;
    while(gets(s1))
    {
          size = 0;
          strcpy(s2,s1);
          strrev(s2); 
          while( strcmp(s1,s2) != 0 ) 
          {
                strcpy(out[size++],s1);
                LL val = atoi(s1)+atoi(s2);
                itoa(val,s1,10);
                //sprintf(s1,"%d",val); 
                strcpy(s2,s1);
                strrev(s2);      
          }               
          strcpy(out[size++],s1);
          printf("%d\n",size-1);
          for( int i = 0; i < size; i++ ) 
               printf( i ?"--->%s":"%s", out[i] );
          puts("");
    }    
    return 0;
}
