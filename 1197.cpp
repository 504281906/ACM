#include<iostream>
using namespace std;
int f(int x,int b)
{
    int s=0;
    while(x>0)
    {
        s+=x%b;
        x/=b;
    }
    return s;
}
int main()
{
    for(int i=1000;i<10000;i++)
    {
        if(f(i,10)==f(i,12)&&f(i,10)==f(i,16))cout<<i<<endl;
    }
    return 0;
}
