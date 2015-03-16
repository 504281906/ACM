#include <stdio.h>
#include <string.h>
#include <string.h>
#include <stdlib.h>
int map[200][200];
int map1[200][200];
int visit[200][200];
int visit1[200][200];

int suma ,sumb;

int dfs(int i , int j , int sit)
{
  // printf("%d %d %d\n",i,j,sit);
     if(sit == 0 )
       {
           if(visit1[i][j] ==  0 && map1[i][j] != 0  )
              {
                 visit1[i][j] = 1 ;
                 dfs(i,j,1);
              }
            if(visit[i+1][j] == 0 && map[i][j] == map[i+1][j])
             {
                 visit[i+1][j] = 1;
                 sumb += 1 ;
                 dfs(i+1,j,0);

             }
            else if(i > 0  && visit[i-1][j] == 0 &&map[i][j] == map[i-1][j])
            {
                  visit[i-1][j] = 1;
                  sumb += 1 ;
                  dfs(i-1,j,0);

            }
       }
     else
     {
         if(visit[i][j] ==  0 && map[i][j] != 0  )
              {
                 visit[i][j] = 1 ;
                 dfs(i,j,0);
              }
         if(visit1[i][j+1] == 0 && map1[i][j] == map1[i][j+1])
             {
                 visit1[i][j+1] = 1;
                 suma += 1 ;
                 dfs(i,j+1,1);

             }
            else if(j > 0  && visit1[i][j-1] == 0 && map1[i][j] == map1[i][j-1] )
            {
                 visit1[i][j-1] = 1;
                 dfs(i,j-1,1);
                 suma += 1 ;

            }

     }
}

int main()
{
   int n , m ;
   while(scanf("%d %d",&n,&m) != EOF)
   {
      int sum = 0 ;
      if(n == 0 && m == 0)
        break;
        memset(map,0,sizeof(map));
        memset(visit,0,sizeof(visit));
        memset(map1,0,sizeof(map1));
        memset(visit1,0,sizeof(visit1));
        int a, b ;
      for(int i =1 ;i<= n ;i ++)
         {
            scanf("%d %d",&a,&b);
            map[a][b] = i ;
            map[a+1][b] = i ;
         }
      for(int i = 1;i <= m;i ++)
      {
          scanf("%d %d",&a,&b);
          map1[a][b] = i ;
          map1[a][b+1] = i ;
      }
      for(int i = 0 ;i <= 102; i ++)
        for(int j = 0; j <= 102; j ++)
        {
            if((visit[i][j] == 0 &&map[i][j]!= 0 ) || ( visit1[i][j] == 0  && map1[i][j] != 0 ))
            {   suma = 0 ;
                sumb = 0 ;

                if(visit[i][j] == 0 &&map[i][j]!= 0  )
                {
                   visit[i][j] = 1;
                   dfs(i , j, 0);

                }
                else if( visit1[i][j] == 0  && map1[i][j] != 0 )
                {
                   visit1[i][j] = 1;
                   dfs(i , j, 1);

                }
               // printf("%d %d\n",suma,sumb);
                if(suma > sumb)
                  sum += suma ;
                else
                  sum += sumb ;
            }
        }
        printf("%d\n",sum);
   }
   return 0 ;
}

