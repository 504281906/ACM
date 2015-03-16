#include <stdio.h>
#include <stdlib.h>
int main()
{
  int n,i,j,m;
  double s,k;
  scanf("%d",&n);
  for (i=1;i<=n;i++)
  {
      s=0;
      scanf("%d",&m);
      for (j=1;j<=m;j++)
      {
          k=j;
      if (j%2==0) s-=1/k;
        else s+=1/k;}
      printf("%.2lf\n",s);
  }
  system("pause");
  return 0;
}
