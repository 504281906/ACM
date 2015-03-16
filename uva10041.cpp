#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{ 
 int s,a[501],i,n,t,T;
 scanf("%d",&T);
 while (T--)
 {
 scanf("%d",&n);
 for (i=1;i<=n;i++)
 scanf("%d",&a[i]);
 s=0; t=(n+1)/2;
 sort(a+1,a+n+1);
 for (i=1;i<=n;i++)
 s=s+abs(a[i]-a[t]);
 printf("%d\n",s);
 }
 return 0;
}
