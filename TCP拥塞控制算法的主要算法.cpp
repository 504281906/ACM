//���ش��ص���ֵ���ش��ص�1
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int a[1000],ss,k,n,m,i;
int main()
{
	cout<<"\t\t\tTCPӵ�������㷨����Ҫ�㷨(���°汾)"<<endl;
	cout<<"��������ֵ�ĳ�ֵ:";
	cin>>ss;
	cout<<endl;
	cout<<"��������ʾ���ִ�:";
	cin>>k;
	cout<<endl;
	cout<<"������ڼ����ִη����ش�:";
	cin>>n;
	cout<<endl;
	cout<<"������ڼ����ִη������ش�:";
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
	cout<<"�ִ�\tӵ������"<<endl;
	for (i=0;i<=k;i++)
		cout<<i<<"\t"<<a[i]<<endl; 
	return 0;
}
