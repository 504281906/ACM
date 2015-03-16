#include <stdio.h>
int gcd(int a,int b)
{
 	if (b==0) return a;
 	else return gcd(b,a%b);
}
int main()
{
 	int gcd(int a,int b);
 	int n,m,k,s,i,j,t,l;
 	int a[1001];
 	scanf("%d",&n);
 	i=1;
 	for (l=1;l<=n;l++)
 	{
 	 scanf("%d",&m);s=1;
    for (i=1;i<=m;i++)
 	{ 
      scanf("%d",&a[i]);
      s=s/gcd(s,a[i])*a[i];
    }
    printf("%d\n",s);
    }
 	return 0;
}
