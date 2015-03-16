#include<stdio.h>
int main()
{
 int m,n,i,a[104],s,j,h,p1,p2;
 while(scanf("%d%d",&n,&m)!=EOF)
 {
 a[0]=2;
 for(i=1;i<n;i++)
 a[i]=a[i-1]+2;
 h=n%m;
 for(j=0;j<n/m;j++)
 {
 s=0;
 for(i=j*m;i<(j+1)*m;i++)
 s=a[i]+s;
 p1=s/m;
 if(j==0)
 printf("%d",p1);
 else printf(" %d",p1);
 }
 if(h!=0)
 {
 s=0;
 for(i=n-h;i<n;i++)
 s=s+a[i];
 p2=s/h;
 printf(" %d",p2);
 }
 printf("\n");
 }
 return 0;
 }
