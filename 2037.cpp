#include<stdio.h>
int main()
{
 int n,a[100],b[100],i,j,t,c[100],flge;
 while(scanf("%d",&n)!=EOF&&n!=0)
 {    
  for(i=0;i<n;i++)
  { 
   scanf("%d%d",&a[i],&b[i]);
  }   
  for(i=0;i<n-1;i++)
   for(j=0;j<n-1-i;j++)
    if(b[j]>b[j+1]) 
    {
     t=b[j];
     b[j]=b[j+1];
     b[j+1]=t; 
     t=a[j];
     a[j]=a[j+1];
     a[j+1]=t;
    }
  flge=0;
  t = 0; 
  for(i=0;i<n;i++) 
  {
   if(a[i]>=t) 
   {
    flge++; 
    t = b[i];
   }
  }
  printf("%d\n",flge);
 }
 return 0;
}
