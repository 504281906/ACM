#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const long long MAXN = 10000000000000000LL;
const int p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

vector<pair<long long, long long> > v;
vector<long long> a;

void gao(int z, long long n, long long m) {
	v.push_back(make_pair(n, m));
	n *= p[z];
	for (int i = 1; n <= MAXN; ++i) {
		gao(z + 1, n, m * (i + 1));
		n *= p[z];
	}
}

int main() {
	long long n;

	gao(0, 1, 1);
	sort(v.begin(), v.end());
	n = v.front().second;
	a.push_back(v.front().first);
	for (size_t i = 2; i < v.size(); ++i) {
		if (n < v[i].second) {
			n = v[i].second;
			a.push_back(v[i].first);
		}
	}
	for (size_t i = 0; i < a.size(); ++i) {
		fprintf(stderr, "%lld\n", a[i]);
	}
	while (scanf("%lld", &n) != EOF) {
		printf("%lld\n", *(upper_bound(a.begin(), a.end(), n) - 1));
	}

	return 0;
}

