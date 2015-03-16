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
string ans[310];
string go(int a,int b){
	string cnt="";
	int l=ans[a].length();
	for (int i=l-1;i>=0;i--){
		for (int j=ans[a][i]-'0'+1;j<=9;j++){
			cnt="";
			int s=j;
			for (int k=0;k<i;k++){
				s+=ans[a][k]-'0';
				cnt+=ans[a][k];
			}
			cnt+=char(j+'0');
			if (s+9*(l-1-i)>=b && s<=b){
				int g=b;
				for (int k=i+1;k<l;k++){
					for (int t=0;t<=9;t++)
						if (s+t+9*(l-k-1)>=g){
							cnt+=char(t+'0');
							g-=t;
							break;
						}
				}
				return cnt;
			}
		}
	}
	for (int i=l+1;;i++){
		for (int j=1;j<=9;j++){
			cnt="";
			int s=j;
			cnt=char(s+'0');
			if (s+9*(i-1)>=b && s<=b){
				int g=b;
				for (int k=0;k<i-1;k++){
					for (int t=0;t<=9;t++)
						if (s+t+9*(i-k-2)>=g){
							cnt+=char(t+'0');
							g-=t;
							break;
						}
				}
				return cnt;
			}
		}
	}
}
int main(){
	int n,k;
	scanf("%d",&n);
	//memset(ans,0,sizeof(ans));
	for (int i=1;i<=n;i++){
		scanf("%d",&k);
		ans[i]=go(i-1,k);
	}
	for (int i=1;i<=n;i++)
		cout<<ans[i]<<endl;
	return 0;
}
