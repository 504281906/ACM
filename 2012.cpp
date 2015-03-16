#include <stdio.h>
int main()
{
    int x,y,i,k;
    int s(int i);
  scanf("%d%d",&x,&y);
  while (x!=0||y!=0)
  {
        k=0;
        if(x>=-39&&x<y&&y<=50)
        {
        for (i=x;i<=y;i++)
         if (s(i)) {printf("Sorry\n");k=1;break;}
         }
         if (k==0) printf("OK\n");
         scanf("%d%d",&x,&y);
  }
  return 0;
}
int s(int i)
{
    int j,a;
    a=i*i+i+41;
    for (j=2;j<=a/2;j++)
    {if (a%j==0) return 1;}
    return 0;
}
