#include <stdio.h>
#include <stdlib.h>
main()
{
     int i,a[10];
     for (i=0;i<10;i++)
      a[i]=0;
     for (i=0;i<10;i++)
      a[i++]=2*i+1;
     for (i=9;i>=0;i--)
      printf("%d ",a[i]);
     system("pause");
}
