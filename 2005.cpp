#include <stdio.h>
int main()
{
    int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    int i,y,d,m,s=0;
    while (scanf("%d/%d/%d",&y,&m,&d)!=EOF)
    {     
          s=0;a[2]=28;
          if (y%400==0 ||(y%4==0 && y%100!=0))
          a[2]++;
          for(i=1;i<=m-1;i++)
           s+=a[i];
           s+=d;
           printf("%d\n",s); 
    }
return 0;
}
