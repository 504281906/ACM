#include <stdio.h>
int main()
{
   int a,y,c,i,j,s;
   scanf ("%d",&a);
   for (j=0;j<a;j++)
	{
     scanf("%d %d",&y,&c);
     s=0;
     for (i=y;i>0;i++)
     {
         if((i%4==0&&i%100!=0)||(i%400==0))
            s++;
         if(s==c) break;
     }
     printf ("%d\n",i);
	}
return 0;
}
