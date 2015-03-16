#include<stdio.h>
#include<stdlib.h>
long f(long n)
{
     long i;
     if (n==1||n==2) i=1;
     else i=f(n-1)+f(n-2);
}
main()
{
      long n;
      scanf("%ld",&n);
      printf("%ld\n",f(n));
      system("pause");
}
q7ntqy5z
