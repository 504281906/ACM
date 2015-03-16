#include<stdio.h>//大数求余，其中n(除数）不是大数 
char a[1000];
int main()
{
 int i,j,k,m,n;
 while(scanf("%s%d",a,&n)!=EOF)
 {
  m=0;
  for(i=0;a[i]!='\0';i++)
   m=((m*10)%n+(a[i]-'0')%n)%n;
  printf("%d\n",m);
  /*__int64 t,y;
  scanf("%I64d%I64d",&t,&y);
  printf("%I64d\n",t % y); */
 }
 return 0;
}
