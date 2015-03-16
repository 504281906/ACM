#include <cstdio>
typedef long long LL;
LL a,b,n,m;
 /*思路：若(a+√b)n == x + y·√b（x、y为整数），则(a－√b)n == x － y·√b。又因为a－1 < √b < a，
  所以0 < (a－√b)n < 1，即x－1 < y·√b < x，所以ceil（(a+√b)n） == 2x。接下来事情就容易多了，
  同时对x、y两部分进行快速幂取模即可*/
int solve() 
{
     LL ans1(1),ans2(0),t1(a),t2(1);
     LL tmp;
     while(n) 
	 {
         if(n&1) 
		 {
             tmp = ans1;
             ans1 = (ans1*t1+ans2*t2*b);
             ans2 = (tmp*t2+ans2*t1);
         }
         tmp = t1;
         t1 = (t1*t1+t2*t2*b);
         t2 = 2*tmp*t2;
         n >>= 1;
     }
     printf("%lld\n",ans1*2%m);
     return 0;
 }
 int main() 
 {
     while(~scanf("%lld%lld%lld%lld",&a,&b,&n,&m))
         solve();
     return 0;
 }
