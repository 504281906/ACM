#include <algorithm>
#include <iostream>
#include <iomanip>
#include <complex>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
using namespace std;
//#pragma comment(linker,"/STACK:102400000,102400000")

string L, R;
int want;
long long dp[21][401][2][2][2][2];
long long weight[21];
long long mod = 1000000007LL;
int pos, value;

long long f(int cur, int sum, int start, int mul, int alreadyLess, int alreadyLarge)
{
	if(cur == L.length())
		return sum == want;
	long long &ret = dp[cur][sum + 200][start][mul][alreadyLess][alreadyLarge];
	if(ret != -1) return ret;
	ret = 0;
	for(int i = 0; i < 10; i++)
	{
		if(cur == pos && (i != value)) continue;
		if(alreadyLarge == false && i < L[cur] - '0') continue;
		if(alreadyLess == false && i > R[cur] - '0') continue;
		ret += f(
					cur + 1,
					sum + i * (mul == 0 ? 1 : -1),
					start | (i > 0),
					(start | (i > 0)) ? (1 - mul) : 0,
					alreadyLess | (i < R[cur] - '0'),
					alreadyLarge | (i > L[cur] - '0')
			    );
		ret %= mod;
	}
	return ret;
}

long long solve(int _pos, int _value)
{
	pos = _pos;
	value = _value;
	memset(dp, 0xff, sizeof(dp));
	return f(0, 0, 0, 0, 0, 0);
}

int MAIN()
{
	cin >> L >> R >> want;
	while(R.length() > L.length())
		L = "0" + L;
	weight[0] = 1;
	for(int i = 1; i <= 18; i++)
		weight[i] = (weight[i-1] * 10) % mod;
	long long ans = 0;
	for(int i = 0; i < L.length(); i++)
		for(int j = 1; j <= 9; j++)
		{
			ans += ((solve(i, j) * j) % mod) * weight[L.length() - i - 1];
			ans %= mod;
		}
	cout << ans << endl;
	return 0;
}

int main()
{
	#ifdef LOCAL_TEST
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif
	ios :: sync_with_stdio(false);
	cout << fixed << setprecision(16);
	return MAIN();
}
