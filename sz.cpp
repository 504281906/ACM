#include<iostream>
#include<string>
#include<memory.h>
using namespace std;
bool is(char a, char b){
	if(a == '(' && b == ')')
		return 1;
	if(a == '[' && b == ']')
		return 1;
	return 0;
}
int main(){
	//dp[i][j] 表示从第i位至第j位的最小匹配长度
	int t, i, j, k, dp[105][105];
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		memset(dp, 0, sizeof(dp));
		for(i = 0; i <= s.length(); ++i){
			dp[i][i] = 1;
		}
		for(i = 2; i <= s.length(); ++i){
			for(j = i - 1; j >= 1; --j){
				dp[j][i] = dp[j][i - 1] + 1;
				for(k = j; k < i; ++k){
					if(is(s[k - 1], s[i - 1])){
						dp[j][i] = min(dp[j][i], dp[j][k - 1] + dp[k + 1][i - 1]);
					}
				}
			}
		}
		cout << dp[1][s.length()] << endl;
	}
	return 0;
}

