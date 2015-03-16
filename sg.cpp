#include <cstdio>
#include <cstring>
int sg[1010];
int f[20];
int mex(int x)
{
  	bool vist[1010];
  	memset(vist,false,sizeof(vist));
  	if (sg[x]!=-1) 
  		return sg[x];
 	for (int i=1;i<=15;i++)
  	{
   		int t=x-f[i];
   		if (t<0) break;
   		sg[t]=mex(t);
  		vist[sg[t]]=true;
  	}
 	for (int i=0;;i++)
  	if (!vist[i])
  	{
  		 sg[x]=i;
  		 break;
 	}
  	return sg[x];
 }
int main()
{
  f[1]=1;f[2]=2;
  for (int i=3;i<=15;i++)
    f[i]=f[i-2]+f[i-1];
  memset(sg,-1,sizeof(sg));
  mex(1000);
  int m,n,p;
  while (~scanf("%d%d%d",&m,&n,&p)& (m+n+p))
  {
   int s=0;
   s^=sg[m]^sg[n]^sg[p];
   if (s) 
   printf("Fibo\n");
   else 
   printf("Nacci\n"); 
  }
}
