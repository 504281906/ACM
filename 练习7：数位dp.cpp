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
LL dp[21][3];
void INIT(){
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for (int i=1;i<=20;i++){
		dp[i][0]=dp[i-1][0]*10-dp[i-1][1];
		dp[i][1]=dp[i-1][0];
		dp[i][2]=dp[i-1][2]*10+dp[i-1][1];
	}
}
int main(){
	INIT();
	int T;
	string s;
	scanf("%d",&T);
	while (T--){
		cin>>s;
		int l=s.length();
		LL ans=0;
		int flag=0;
		int pre=0;
		for (int i=0;i<l;i++){
			int t=s[i]-'0';
			ans+=t*dp[l-i-1][2];
			if (flag) ans+=t*dp[l-1-i][0];
			else if (t>4) ans+=dp[l-1-i][1];
			if (flag==0 && pre==4 && t==9)
			{
				flag=1;
				ans++;
			}
			pre=t;
		}
		cout<<ans<<endl;
	}
	return 0;
}
