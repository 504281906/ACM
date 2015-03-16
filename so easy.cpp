#include <cstdio>
typedef long long LL;
LL a,b,n,m;
 /*˼·����(a+��b)n == x + y����b��x��yΪ����������(a����b)n == x �� y����b������Ϊa��1 < ��b < a��
  ����0 < (a����b)n < 1����x��1 < y����b < x������ceil��(a+��b)n�� == 2x����������������׶��ˣ�
  ͬʱ��x��y�����ֽ��п�����ȡģ����*/
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
