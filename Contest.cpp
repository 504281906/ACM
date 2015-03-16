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
#define pi acos(-1)
using namespace std;
int main(){
	double a,b,c,d;
	while(~scanf("%lf%lf%lf%lf",&a,&b,&c,&d)){
		double s1=max(3.0*a/10,a-a/250*c);
		double s2=max(3.0*b/10,b-b/250*d);
		if (s1>s2) cout<<"Misha"<<endl;
		else if (s2>s1) cout<<"Vasya"<<endl;
		else cout<<"Tie"<<endl;
	}
	return 0;
}
