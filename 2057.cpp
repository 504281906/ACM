#include <stdio.h>
int main (  )
{
 __int64 a, b;
 while (scanf("%I64X%I64X",&a,&b)!=EOF)
 {
  b+=a;
  if(b<0)
  {
   b=-b;
   a='-';
  }
  else
  a=0;
  if (a)
  putchar(a);
  printf ("%I64X\n",b);
 }
 return 0;
}
