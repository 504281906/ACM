#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int a[1000][1000];
int ths[1000][1000];
int temp[1000];
int main()
{
   int n , m;
   while(scanf("%d %d",&n,&m) != EOF)
   {
     memset(a,0,sizeof(a));

     memset(temp,0,sizeof(temp));
     memset(ths,0,sizeof(ths));
     int k;
     for(int i = 1;i <= m;i ++)
     {    k = (i-1)%n+1;
          a[i][1] = k;
          ths[i][a[i][1]] = 1;
     }
     for(int i = 1;i <= n;i ++)
     {
        temp[i] = (k)%n + 1 ;
     }
     for(int i = 1;i <= m; i ++)
     {
        if(temp[a[i][1]] == a[i][1])
            temp[a[i][1]] =  temp[a[i][1]]%n +1;
        a[i][2] = temp[a[i][1]];
        ths[i][a[i][2]] = 1;
        temp[a[i][1]] = temp[a[i][1]] % n + 1;
     }
    for(int i = 1;i <= m;i ++)
    {
       int be = 1;
       for(int j = 3; j<= n;j ++)
       {
           while(ths[i][be] == 1)
             be++;
           a[i][j] = be;
           ths[i][be] = 1;
       }
    }
    for(int i = 1;i <= m;i ++)
    {
      for(int j = 1;j <= n;j ++)
        printf(j == 1?"%d":" %d",a[i][j]);
      printf("\n");
    }
   }
  return 0 ;
}

