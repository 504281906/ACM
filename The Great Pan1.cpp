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
using namespace std;
#define LL long long 
LL ans = 0 ;
char str1[1000000];
char str[10000000];
int main(){
    int n; 
    while(scanf("%d",&n) != EOF)
    {
    int len = 0;
        getchar();
        for(int i =1 ;i <= n;i ++)
        {
        //    printf("%d\n",i);
            gets(str1);
            int len1 = strlen(str1);
          //  printf("%d\n",len1);
            for(int j = 0 ;j < len1 ;j++)
                str[j+len] = str1[j];
            len = len + len1;
        }
        int is = 0 ;
        ans = 1; 
        int t  = 0 ;
        LL tans = 1 ;
        int ok = 0 ; 
        for(int i = 0 ;i < len ;i ++)
        {
            if(ok == 1)
                break;
            if(is)    
            {
               if(str[i] == ' ')
               {
                    t++;
                    if(str[i+1] != ' ')
                    {
                        tans *=(t+1);
                        t = 0 ; 
                    }
               }else if(str[i] == '$'){
                   is = 0 ;
                   ans = tans * ans;
                   tans = 1; 
               }
               if(ans > 100000 || tans > 100000)
                {
                     ok = 1; 
                }
            }else {
             //  printf("****\n");
               if(str[i] == '{')
                {
            //       printf("****\n");
                   int t = 1 ; 
                   int j ;
                   for(j = i +1; ;j ++)
                   {
                       if(str[j] == '}') 
                           break;
                       if(str[j] == '|')
                           t ++ ; 
                   }
                   i = j;
                   ans *= t ; 
                   if(ans > 100000)
                   {
                     ok  = 1; 
                   }
                }else{
                   if(str[i] == '$')
                       is = 1; 
                }
            }
    //        printf("%I64d %d\n",ans,i);
        }
        if(ans > 100000 || ok )
            printf("doge\n");
        else 
            printf("%I64d\n",ans);
    }
    return 0;
}
