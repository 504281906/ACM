#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const double inf = 100000000.0;

double dp[1010][110][10];
int f[10];

void init() {
	f[0] = 1;
	for (int i = 1; i < 10; i++)
		f[i] = f[i-1] * 2;
}

double cal(int p1, int p2, int t1, int t2, int p) {
	if (p >= p2)	
		return t2;
	if (p < p1)
		return inf;
	return (double)t1 - 1.0*(t1-t2)/(p2-p1)*(p-p1);
}

int main() {
	int n, p, p1, p2, t1, t2, w1, w2;
	init();
	while (scanf("%d%d", &n, &p) != EOF && n+p) {
		scanf("%d%d%d%d%d%d", &p1, &p2, &t1, &t2, &w1, &w2);
		for (int i = 0; i <= 1005; i++)
			for (int j = 0; j <= 105; j++)
				for (int k = 0; k <= 9; k++)
					dp[i][j][k] = inf;
		int np = p + w1;
		dp[1][min(np, 100)][min(w2, 7)] = cal(p1, p2, t1, t2, p);

		for (int i = 2; i <= n; i++) {
			scanf("%d%d%d%d%d%d", &p1, &p2, &t1, &t2, &w1, &w2);
			for (int j = 1; j <= 100; j++)
				for (int k = 0; k <= 7; k++) 
					for (int l = 0; l <= k; l++) {
						int nu = j*f[l] + w1;
						int nk = k + w2 - l;
						double tmp = cal(p1, p2, t1, t2, j*f[l]);
						dp[i][min(nu, 100)][min(nk, 7)] = min(dp[i][min(nu, 100)][min(nk, 7)], dp[i-1][j][k]+tmp);
					}
		}	

		double ans = inf;
		for (int i = 1; i <= 100; i++)
			for (int j = 0; j <= 7; j++) 
				ans = min(ans, dp[n][i][j]);
		if (ans < inf)
			printf("%.2lf\n", ans);
		else printf("Impossible\n");
	} 	
	return 0;
}
