#include<iostream>
#include<cstring>
using namespace std;
const int mm=110;
int a[mm],b[mm],c[mm];
int n,m;
bool flag;
void dfs(int u,int col)
{
  if(c[u]==-1)
  {
    c[u]=col;
    for(int i=0;i<m;i++)///���ཻ
    {
      if(a[u]!=a[i]&&b[u]!=b[i])
      {
        if(a[u]<a[i]&&b[u]>a[i]&&b[u]<b[i])
          dfs(i,col^1);
        if(a[i]<a[u]&&b[i]>a[u]&&b[i]<b[u])
          dfs(i,col^1);
      }
    }
  }
  else if(c[u]^col)flag=0;
}
int main()
{
  while(cin>>n>>m)
  { flag=1;
    memset(c,-1,sizeof(c));
    for(int i=0;i<m;i++)
    {
      cin>>a[i]>>b[i];a[i]--,b[i]--;
      if(a[i]>b[i])a[i]^=b[i],b[i]^=a[i],a[i]^=b[i];///a<b
    }
    for(int i=0;i<m;i++)
      if(c[i]==-1)
      dfs(i,0);
    if(flag)
      for(int i=0;i<m;i++)
      cout<<(c[i]?'i':'o');
    else cout<<"Impossible\n";
    cout<<"\n";
  }
}

