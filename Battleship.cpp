#include<vector>
#include<list>
#include<map>
#include<set>
#include<deque>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<ctime>
#define LL long long

using namespace std;
int mp[20][20];
int check(int i,int j)
{
    int sum = 0 ;
    if(i <= 10 && i >= 1 && j <= 10 && j >=1 )
    {
       sum += mp[i+1][j] + mp[i][j] + mp[i-1][j] +mp[i][j+1] + mp[i][j-1] + mp[i+1][j+1] + mp[i+1][j-1] + mp[i-1][j+1] + mp[i-1][j-1] ;
       if(sum == 0 )
         return 1;
        return 0 ; 
    }
    return 0 ;
}
int ship[] = {0,4,3,3,2,2,2,1,1,1,1};
int hs[20];
int dfs(int x, int y , int k ,int dis)
{
   if(k == 1 )
       return  1;
   if(dis == 1)
   {
      int tx = x + 1; 
      int ty = y;
      if(check(tx,ty))
      {
          if(dfs(tx,ty,k-1,dis))
          {
             mp[tx][ty] =1 ;
             return 1;
          }
      }else{
          return 0 ; 
      }
   }else if(dis == 2){
      int tx = x -1; 
      int ty = y;
      if(check(tx,ty))
      {
          if(dfs(tx,ty,k-1,dis))
          {
             mp[tx][ty] =1 ;
             return 1;
          }
      }else{
          return 0 ; 
      }
   
   }else if(dis == 3){
      int tx = x; 
      int ty = y+1;
      if(check(tx,ty))
      {
          if(dfs(tx,ty,k-1,dis))
          {
             mp[tx][ty] =1 ;
             return 1;
          }
      }else{
          return 0 ; 
      }
   
   }else {
      int tx = x; 
      int ty = y-1;
      if(check(tx,ty))
      {
          if(dfs(tx,ty,k-1,dis))
          {
             mp[tx][ty] =1 ;
             return 1;
          }
      }else{
          return 0 ; 
      }
   
   }
   return 0 ;
}
void solve(int x, int y )
{
   //printf("%d %d\n",x,y);
   for(int i = 1;i <= 9 ;i ++)
       if(hs[i] == 0 )
       for(int j = 1;j <= 4 ;j ++)
       {
           if(dfs(x,y,ship[i],j))
           { 
               mp[x][y] = 1;
               hs[i] = 1; 
               return ;
           }
       }
}
int main(){
    int temp ; 
    while(scanf("%d",&temp) != EOF)
    {
        memset(mp,0,sizeof(mp));
        memset(hs,0,sizeof(hs));
        if(temp == 100 )
        {
            mp[1][1] = 1; 
        }
        for(int  i = 2;i <= 10;i ++)
        {
            scanf("%d",&temp);
            if(temp == 100 )
            {
                mp[1][i] = 1; 
            }
        }
        for(int i = 2;i <= 10;i ++)
        {

            for(int j = 1;j <= 10; j ++)
            {
                scanf("%d",&temp);
                if(temp == 100 )
                {
                   mp[i][j] = 1; 
                }
            }
        }
        for(int i =1;i <= 10;i ++)
        {
           for(int j = 1;j <= 10; j ++)
           {
              if(check(i,j))
              {
                  solve(i,j);
              }
           }
        }
        for(int i =1;i <= 10 ;i ++)
        {    for(int j = 1;j <= 10 ;j ++)
            {
              if(mp[i][j])
              {
                printf("#");
              }else printf(".");
            }
            printf("\n");
        }
    }
    return 0;
}
