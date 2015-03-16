#include<iostream>
using namespace std;
int x,y,q;
void extend_Euclid(int a,int b)
{
    if (b==0)
    {    x=1; y=0; q=a;}
    else
    {
        extend_Euclid(b,a%b);
        int temp=x;
        x=y; y=temp-a/b*y;
    }
}
int main()
{
    int a,b;
    cin>>a>>b;
   // if (a<b) swap(a,b);
    extend_Euclid(a,-b);
    printf("%d=(%d)*%d+(%d)*%d\n",q,x,a,y,b);
}
