#include <iostream>  
#include <math.h>  
using namespace std;  
int main()  
{  
    long long int n,m,i,j,s,dif,x;  
    while(cin>>n)  
    {  
        if(n==0)  
        {  
            break;  
        }  
        i=(int)(sqrt(double(1+n))-1+0.01)+1;  
        s=(i-1)*(i-1)+2*(i-1);  
        dif=n-s;  
        if(dif==1)  
        {  
            cout<<"yes"<<endl;  
        }else  
        {  
            cout<<"no"<<endl;  
        }  
    }  
    return 0;  
}  
