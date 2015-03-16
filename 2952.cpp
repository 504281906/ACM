#include <cstdio>
#include <cctype>
#include <algorithm>
using namespace std;

int x[200002], y[200002];

inline int getnum()
{
	bool flag = false;
	char ch;
	int ret = 0;

	while((ch=getchar()) == ' ');
	if(ch == '-') {
		flag = true;
		ch = getchar();
	}
	do {
		ret *= 10;
		ret += ch - '0';
	}while(isdigit(ch=getchar()));
	if(flag) ret = -ret;

	return ret;
}

int main(void)
{
	int re, i, n, a, ans;

	scanf("%d", &re);
	while(re--) {
		scanf("%d ", &n);
		x[0] = 0;
		for (i = 1; i <= n; ++i) {
			x[i] = getnum();
			x[i] += x[i - 1];
		}
		y[n] = x[n];
		for (i = n - 1; i > 0; --i)
			y[i] = min(x[i], y[i + 1]);
		x[0] = x[1];
		ans = (y[1] > 0) ? 1 : 0;
		for (i = 1; i < n; ++i) {
			a = x[i];
			if(x[i - 1] < x[i]) x[i] = x[i - 1];
			if(y[i + 1] - a > 0 && x[i] + x[n] - a > 0) ++ans;
		}
		printf("%d\n", ans);
	}

	return 0;
}

