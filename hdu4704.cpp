/*����:��ĿҪ��s1+s2+s3+...+sn;//si��ʾn����i������n�Ļ��ֵĸ���,��n=4,��s1=1,s2=3
����An=s1+s2+s3+...+sn;
����n�����Ȼ��ֵ�һ����Ϊn,n-1,n-2,...,1�������׵ó�An=A0+A1+A2+A3+...+A(n-1);
=>A(n+1)=A0+A1+A2+A3+...+An =>An=2^(n-1);
����n�ǳ���,��������Ҫ�õ�����С����:a^(p-1)%p == 1%p == 1;//pΪ����
����2^n%m == ( 2^(n%(m-1))*2^(n/(m-1)*(m-1)) )%m == (2^(n%(m-1)))%m * ((2^k)^(m-1))%m == (2^(n%(m-1)))%m;//k=n/(m-1)
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
#define INF 99999999
using namespace std;

const int MAX=100000+10;
const int mod=1000000000+7;
char s[MAX];

__int64 MOD(char *a,int Mod){
	__int64 sum=0;
	for(int i=0;a[i] != '\0';++i){
		sum=(sum*10+a[i]-'0')%Mod;
	}
	return sum;
}

__int64 FastPow(__int64 a,__int64 k){
	k=(k+mod)%mod;
	__int64 sum=1;
	while(k){
		if(k&1)sum=sum*a%mod;
		a=a*a%mod;
		k>>=1;
	}
	return sum;
}

int main(){
	while(scanf("%s",s)!=EOF){
		__int64 n=MOD(s,mod-1)-1;
		printf("%I64d\n",FastPow(2,n));
	}
	return 0;
}
