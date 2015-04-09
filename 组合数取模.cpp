#include<cstdio>
 #include<memory>
 using namespace std;
 const int mod=10007;
 int a[mod];
 void init()
 {
 int i;
     a[0]=1;
 for(i=1;i<mod;i++)
    a[i]=(a[i-1]*i)%mod;
 }
 int gcd(int a,int b){
 if(b==0) return a;
 return gcd(b,a%b);
 }
void e_gcd(int a,int b,int &x,int &y) //扩展欧几里得定理：解ax+by==1。
 {
     if(!b)
     {
         x=1;
         y=0;
     }
     else
     {
         e_gcd(b,a%b,x,y);
         int l=x;
         x=y;
         y=l-a/b*y;
     }
 }
int choose(int n,int m)   
 {
     if(m>n)
    return 0;
 else if(n==m)
    return 1;
 int nn=a[n],mm=(a[m]*a[n-m])%mod;
 int d=gcd(nn,mm);
 nn/=d;
 mm/=d;
     int x,y;
     e_gcd(mm,mod,x,y);
 x=(x+mod)%mod;
     return (x*nn)%mod;
 }
 int main( )
 {
 int t;
 scanf("%d",&t);
 init();
 while(t--)
 {
    int e[100],f[100];
    int i=0,j,m,n;
    memset(e,0,sizeof(e));
    memset(f,0,sizeof(f));
    scanf("%d %d",&n,&m);
    while(n>0)
    {
     e[i++]=n%mod;
     n=n/mod;
    }
    int len=i;
    i=0;
    while(m>0)
    {
            f[i++]=m%mod;
      m=m/mod;
    }
    int re=1;
         for(i=0;i<len;i++)
    {
            re=(re*choose(e[i],f[i]))%mod;
    }
    printf("%d\n",re%mod);
 }
 return 0;
 }
