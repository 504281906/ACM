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
LL c(double x)
{
   return x + 1; 
}
#define eps 1e-8
int main(){
  LL   x ,k;
  int ca = 0 ; 
  while(scanf("%I64d %I64d",&x,&k) != EOF)
  {
      ca ++ ; 
      if(x == k && k == 0)
      {
         break;
      }
      LL i;
      for(i = 1;i <= k;i++)
      {
          if(x % i != 0 )
          {
             x = c(x/i)*i;
          }
          if(1ll*i*(i+1) > x)
              break;
      }
      if(i < k )
      {
         x = (x/i)*k;
      }
      printf("Case #%d: %I64d\n",ca,x);
  }
return 0;
}
