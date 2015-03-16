#include<stdio.h>
#define M 1009
int p[M];
void Make_set(int n)
{
 int i;
 for(i=1;i<=n;i++)
  p[i]=i;
}
int find(int a)
{
 int i,r=a;
 while(p[r]!=r)
 {
  r=p[r];
 }
 while(a!=r)
 {
  i=p[a];
  p[a]=r;
  a=i;
 }
 return a;
}
int main()
{
 int i,j,n,m,t,k,a,b,num,f1,f2;
 scanf("%d",&t);
 for(k=1;k<=t;k++)
 {
  scanf("%d%d",&n,&m);
  Make_set(n);
  for(i=1;i<=m;i++)
  {
   scanf("%d%d",&a,&b);
   f1=find(a);
   f2=find(b);
   if(f1!=f2)
    p[f1]=f2;
  }
  num=0;
  for(j=1;j<=n;j++)
  {
   if(p[j]==j)
    num++;
  }
  printf("%d\n",num);
 }
 return 0;
}











#include <stdio.h>
#include <string.h>
int main()
{
	int k,s,n,m,i;
	int a[2000],b[2001],c[2001];
	scanf("%d",&k);
	while (k--)
	{
		s=0;
		scanf("%d%d",&n,&m);
		for (i=1;i<=n;i++)
		 {c[i]=1;a[i]=0;b[i]=0;}
		for (i=1;i<=m;i++)
		 scanf("%d%d",&a[i],&b[i]);
		for (i=1;i<=n;i++)
		    if (c[b[i]]==0)	c[a[i]]=0;
	          else c[b[i]]=0;
		for (i=1;i<=n;i++)
		 s+=c[i];
		if (s!=0) printf("%d\n\n",s);
		else printf("1\n\n");
	}
	return 0;
}
