#include <iostream>
#include <string>
using namespace std;
void f(string& a){
    string::iterator it;
    int flag=0;
    it=a.begin();
    while(*it=='0')a.erase(it);
    while(it!=a.end())
        if(*it++=='.')flag=1;
    if(flag)
	{
        it=a.end()-1;
        while(*it=='0')a.erase(it--);
        if(*it=='.')a.erase(it);
    }
}
int main()
{
    string a,b;
    while(cin>>a>>b){
        f(a);f(b);
        if(a==b)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
