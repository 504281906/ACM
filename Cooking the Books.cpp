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
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int T;
	string s;
	scanf("%d",&T);
	int cas=1;
	while (T--){
		cin>>s;
		//cout<<s;
		string ss=s;
		int l=s.length();
		int p1[2]={0,0},p2[2]={0,0};
		int f1=0,f2=0;
		for (int i=0;i<l;i++){
			if (f1+f2==2) break;
			if (f1==0){
				p1[0]=i;
				char s1=s[i];
				for (int j=i+1;j<l;j++)
					if (s[j]<=s1 && (s[j]!='0' || (s[j]=='0' && i!=0))){
						p1[1]=j;
						s1=s[j];
						f1=1;
					}
			}
			if (f2==0){
				p2[0]=i;
				char s1=s[i];
				for (int j=i+1;j<l;j++)
					if (s[j]>=s1){
						p2[1]=j;
						f2=1;
						s1=s[j];
					}
			}
		}
		printf("Case #%d: ",cas++);
		char sk;
		if (f1){
			sk=s[p1[0]];
			s[p1[0]]=s[p1[1]];
			s[p1[1]]=sk;
		}
		if (f2){
			sk=ss[p2[0]];
			ss[p2[0]]=ss[p2[1]];
			ss[p2[1]]=sk;
		}
		cout<<s<<" "<<ss<<endl;
	}
	return 0;
}
