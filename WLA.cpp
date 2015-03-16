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
#include <string>
#define LL __int64
#define eps 1e-8
using namespace std;
int main(){
	int T;
	scanf("%d",&T);
	getchar();
	while (T--){
		string s;
		int ans=0;
		string ss="WLA";
		getline(cin,s);
		int l=s.length();
		string s1="";
		int i;
		for (i=0;i<l;){
			while(s[i]!=' ' && i<l){
				 s1+=s[i];
				 i++;
			}
			if (s1==ss) ans++;
			s1="";
			i++;
		}
		if (ans & 1) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
