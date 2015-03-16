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
		double h=1.0-(0.05*k)/(1+0.05*k); //伤害系数 
		double hit=s*h;   // 每秒对面英雄造成的实际伤害
		double m=hit*10;  //10秒之内造成的实际伤害的总和
		if (m>=n) cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
	return 0;
}
