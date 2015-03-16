//快重传回到阈值，重传回到1
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int a[1000],ss,k,n,m,i;
int main()
{
	cout<<"\t\t\tTCP拥塞控制算法的主要算法(最新版本)"<<endl;
	cout<<"请输入阈值的初值:";
	cin>>ss;
	cout<<endl;
	cout<<"请输入显示的轮次:";
	cin>>k;
	cout<<endl;
	cout<<"请输入第几个轮次发生重传:";
	cin>>n;
	cout<<endl;
	cout<<"请输入第几个轮次发生快重传:";
	cin>>m;
	cout<<endl; 
	long long cwnd=1;
	int flag=1;
	a[0]=1;
	for (i=1;i<=k;i++){
		if (i==n){
			ss=cwnd/2;
			cwnd=1;
			a[i]=cwnd;
			flag=1;
		}else if (i==m){
			ss=cwnd/2;
			cwnd=ss;
			a[i]=ss;
			flag=0;
		}else {
		if (flag){
			cwnd*=2;
			a[i]=cwnd;
			if (cwnd*2>=ss){
				if (i+1!=m && i+1!=n && cwnd<ss){
					a[++i]=ss;
					cwnd=ss;
				}//else cwnd/=2;
				flag=0;
			}
		}else{
			cwnd++;
			a[i]=cwnd;
		}
		}
	}
	cout<<"轮次\t拥塞窗口"<<endl;
	for (i=0;i<=k;i++)
		cout<<i<<"\t"<<a[i]<<endl; 
	return 0;
}
