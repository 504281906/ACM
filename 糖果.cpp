#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int N = 100005;

int a[N];
int s[N];
int n;
struct Node {
	int l, r;
}el[N], er[N];

void solve() {
	if (a[1] == -1 && a[2] == -1) {
		el[1].l = el[2].l = 0;
		el[1].r = el[2].r = s[1];
	} else if (a[1] == -1) {
		el[1].l = el[1].r = s[1] - a[2];
		el[2].l = el[2].r = a[2];
	} else if (a[2] == -1) {
		el[1].l = el[1].r = a[1];
		el[2].l = el[2].r = s[1] - a[1];
	} else {
		el[1].l = el[1].r = a[1];
		el[2].l = el[2].r = a[2];
	}
	el[3].l = el[3].r = s[2] - s[1];
	for (int i = 4; i <= n; ++i) { // ¥”◊ÛÕ˘”“
		if (a[i] == -1) {
			el[i].l = s[i-1]-el[i-1].r-el[i-2].r;
			el[i].r = s[i-1]-el[i-1].l-el[i-2].l;
		} else {
			el[i].l = el[i].r = a[i];	
		}
	}
	
	if (a[n] == -1 && a[n-1] == -1) {
		er[n].l = er[n-1].l = 0;
		er[n].r = er[n-1].r = s[n];
	} else if (a[n] == -1) {
		er[n].l = er[n].r = s[n]-a[n-1];
		er[n-1].l = er[n-1].r = a[n-1];
	} else if (a[n-1] == -1) {
		er[n].l = er[n].r = a[n];
		er[n-1].l = er[n-1].r = s[n]-a[n];
	} else {
		er[n].l = er[n].r = a[n];
		er[n-1].l = er[n-1].r = a[n-1];
	}
	er[n-3].l = er[n-3].r = s[n-1] - s[n];
	for (int i = n-4; i >= 1; --i) { // ¥””“Õ˘◊Û
		if (a[i] == -1) {
			er[i].l = s[i+1]-er[i+1].r-er[i+2].r;
			er[i].r = s[i+1]-er[i+1].l-er[i+2].l;
		} else {
			er[i].l = er[i].r = a[i];
		}
	}
}

int cal(int q) {
	return min(el[q].r, er[q].r);
}

int main() {
	while (scanf("%d", &n) != EOF) {
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &s[i]);
		}
		solve();
		int m, q;
		scanf("%d", &m);
		while (m--) {
			scanf("%d", &q);
			printf("%d\n", cal(q+1));
		}
	}
	return 0;
}

