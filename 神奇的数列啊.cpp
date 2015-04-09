#include<iostream> 
#include<cstdio>
using namespace std;

int main()
{
 int T;
 int N;
 cin>>T;
 for(int i = 0;i< T;i++)
 {
  cin>>N;
  if(N == 1 || N ==2)
   cout<<"Case "<<i+1<<": no solution"<<endl;
  else
  {
   int x = N-1;
   int y = 2*x;
   int z = 1;
   cout<<"Case "<<i+1<<": "<<y<<" "<<x<<" "<<z<<endl;
  }
 }
 return 0;
}
