#include <map>
#include <set>
#include <list>
#include <ctime>
#include <cmath>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <cstdio>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 100000 + 10;
int n, m, size, a[maxn], dep[maxn], f[maxn][20];
int fa[17][maxn], o[maxn], prev[17][maxn][2];
vector<int> e[maxn];

int get_bit(int s, int k)
{
    return (s >> k) & 1;
}

void buildTree(int u, int p)
{
    o[size ++] = u;
    dep[u] = dep[p] + 1;
    f[u][0] = p;
    for (int i = 1; i < 20; i ++) {
        int j = f[u][i - 1];
        f[u][i] = f[j][i - 1];
    }
    for (int i = 0; i < e[u].size(); i ++)
    if (e[u][i] != p) {
        buildTree(e[u][i], u);
    }
}

int jump(int u, int d)
{
    for (int i = 0; i < 20; i ++)
    if (get_bit(d, i) == 1) {
        u = f[u][i];
    }
    return u;
}

int get_lca(int u, int v)
{
    if (dep[u] < dep[v]) swap(u, v);
    u = jump(u, dep[u] - dep[v]);
    if (u == v) return u;
    for (int i = 19; i >= 0; i --)
    if (f[u][i] != f[v][i]) {
        u = f[u][i];
        v = f[v][i];
    }
    return f[u][0];
}

int main()
{
    while (scanf("%d%d", &n, &m) != EOF) {
        for (int i = 1; i <= n; i ++) {
            scanf("%d", &a[i]);
            e[i].clear();
        }
        for (int i = 1; i < n; i ++) {
            int x, y;
            scanf("%d%d", &x, &y);
            e[x].push_back(y);
            e[y].push_back(x);
        }
        size = 0;
        buildTree(1, 0);
        for (int i = 1; i <= n; i ++) {
            fa[16][i] = f[i][0];
        }
        for (int k = 15; k >= 0; k --) {
            for (int i = 0; i < n; i ++) {
                int j = o[i];
                prev[k][j][0] = prev[k][fa[k + 1][j]][0];
                prev[k][j][1] = prev[k][fa[k + 1][j]][1];
                int x = get_bit(a[j], k);
                fa[k][j] = prev[k][j][x];
                prev[k][j][x] = j;
            }
        }
        for (int i = 0; i < m; i ++) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            int p = get_lca(u, v);
            int s = w & 65535;
            int ans = w - s;
            for (int k = 15; k >= 0; k --) {
                int x = get_bit(s, k) ^ 1;
                int pu = prev[k][u][x];
                int pv = prev[k][v][x];
                if ((dep[pu] >= dep[p]) || (dep[pv] >= dep[p])) {
                    u = pu;
                    v = pv;
                    ans += 1 << k;
                } else {
                    u = prev[k][u][x ^ 1];
                    v = prev[k][v][x ^ 1];
                }
            }
            printf("%d\n", ans);
        }
    }
    return 0 ;
}

