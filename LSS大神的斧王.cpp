#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
#include <map>
#include <stack>
#include <list>
#include <vector>
#include <ctime>
#define LL __int64
#define eps 1e-8
using namespace std;
int main(){
	int T;
	double n,k,s;
	scanf("%d",&T);
	//freopen("out.txt","w",stdout);
	while (T--){
		scanf("%lf%lf%lf",&n,&k,&s);
		double h=1.0-(0.05*k)/(1+0.05*k); //�˺�ϵ�� 
		double hit=s*h;   // ÿ�����Ӣ����ɵ�ʵ���˺�
		double m=hit*10;  //10��֮����ɵ�ʵ���˺����ܺ�
		if (m>=n) cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
	return 0;
}
