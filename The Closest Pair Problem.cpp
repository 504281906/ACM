#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define sqr(x) ((x) * (x))
#define dis(i, j) (sqrt(sqr(p[i].x - p[j].x) + sqr(p[i].y - p[j].y)))

const int MAXN = 10010;
struct Point {
  double x;
  double y;
} p[MAXN];
int n, t[MAXN];
double Min;

bool cmp1(Point a, Point b) {
  return a.x < b.x;
}

bool cmp2(int a, int b) {
  return p[a].y < p[b].y;
}

double solve(int l, int r) {
  if (l == r) return 0xfffffff;
  if (l + 1 == r) return dis(l, r);
  int mid = (l + r) / 2;
  double d = min(solve(l, mid), solve(mid + 1, r));
  int c = 0;
  for (int i = l; i <= r; i++)
    if (fabs(p[mid].x - p[i].x) <= d)
      t[c++] = i;
  sort(t, t + c, cmp2);
  for (int i = 0; i < c; i++)
    for (int j = i + 1; j < c && p[t[j]].y - p[t[i]].y < d; j++) {
      double td = dis(t[i], t[j]);
      if (d - td > 1e-9) d = td;
    }
  return d;
}

int main() {
  while (scanf("%d", &n) && n) {
    rep(i, n) scanf("%lf%lf", &p[i].x, &p[i].y);
    sort(p, p + n, cmp1);
    Min = solve(0, n - 1);
    if (Min - 10000 <= 1e-9) printf("%.4lf\n", Min);
    else printf("INFINITY\n");
  }
  return 0;
}
