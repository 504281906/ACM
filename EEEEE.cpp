#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxn 2000
int hs[2005];
int a[2005];
int b[2005];
int k= 0;
void sai()
{
  memset(hs,0,sizeof(hs));
  hs[1] = 1 ;
  for(int i = 2;i <= maxn; i ++)
    {
      if(hs[i] == 0)
      {
       int k = i * i ;
       while(k <= maxn)
       {
         hs[k] = 1;
         k += i ;
       }
      }
    }
  for(int i = 1;i <= maxn;i ++)
   {
     if(hs[i] == 0 )
       {
        k ++;
        b[k] = i ;
       }
   }
}
long long dpow(int t ,int n)
{
   long long ans = 1;
   for(int i = 1;i <= n;i ++)
    {
        ans *= t;
    }
   return ans;
}
void su(int n)
{
   for(int i = 1;i <= k;)
   {
     if(n % b[i] == 0 )
     {
        a[i] ++ ;
        n = n /b[i];
     }else i++;
     if(n == 0 )
       return ;
   }
}
long long num[20];
int main()
{
  sai();
  int n;
  scanf("%d",&n);
  memset(a,0,sizeof(a));
  int p = 0 ;
  long long ans = 1 ;
  if(n == 1 ){
   printf("1\n");
   return 0;
  }else {
     su(n);

     for(int i = maxn ;i >= 1;i --)
     {
        while(a[i] != 0)
         {
             p ++;
             if(p == 1 )
              {
                  num[1] = b[i];
                  a[i] --;
                  continue;
              }
             long long temp = dpow(b[p],b[i]-1);
             long long min = temp;
             long long minci = b[i];
             long long numci = p;
             for(int j = 1;j < p ;j ++)//ÅÐ¶ÏÊÇ·ñÐ¡ÓÚ
             {
                 int ci = b[i] * num[j] - num[j];
                 long long temp2 = 1;
                 int ok = 1;
                 for(int s = 1; s <= ci ;s ++)
                     {
                       temp2 *= b[j];
                       if(temp2 > min)
                       {
                         ok = 0;
                         break;
                       }
                     }
                 if(ok)
                 {
                     min = temp2 ;
                     minci = ci;
                     numci = j ;
                 }
             }
             num[numci] += minci;
             if(numci != p)
                   p--;
             a[i] --;
         }
     }
     long long ans = 1;
   /*  for(int i= 1; i<= p ;i ++)
       printf("%d %d\n",b[i],num[i] - 1);*/
     for(int i =1;i <= p ;i ++)
       ans *= dpow(b[i],num[i]-1);
     printf("%I64d\n",ans);
  }
  return 0;
}
