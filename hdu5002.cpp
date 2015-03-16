#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 200005;
const int INF = 1000000000;

struct Node {
    int firstV, firstCnt, secondV, secondCnt, size;
    int tag1, tag2;

    void init() {
        scanf("%d", &firstV);
        size = 1;
        firstCnt = 1;
        secondV = -INF;
        secondCnt = 0;
        tag1 = INF;
        tag2 = 0;
    }

    void change(const int &v) {
        firstV = v;
        firstCnt = size;
        secondV = -INF;
        secondCnt = 0;
        tag1 = v;
        tag2 = 0;
    }

    void add(const int &v) {
        firstV += v;
        if (secondV != -INF) {
            secondV += v;
        }

        tag2 += v;
    }
};

Node merge(const Node &a, const Node &b) {
    Node ret;
    int v[5];
    ret.size = a.size + b.size;
    v[1] = a.firstV, v[2] = a.secondV;
    v[3] = b.firstV, v[4] = b.secondV;
    sort(v + 1, v + 5);
    reverse(v + 1, v + 5);
    unique(v + 1, v + 5);
    ret.firstV = v[1];
    ret.firstCnt = 0;
    ret.secondV = v[2];
    ret.secondCnt = 0;
    if (a.firstV == ret.firstV) {
        ret.firstCnt += a.firstCnt;
    }

    if (a.secondV == ret.firstV) {
        ret.firstCnt += a.secondCnt;
    }

    if (b.firstV == ret.firstV) {
        ret.firstCnt += b.firstCnt;
    }

    if (b.secondV == ret.firstV) {
        ret.firstCnt += b.secondCnt;
    }

    if (a.firstV == ret.secondV) {
        ret.secondCnt += a.firstCnt;
    }

    if (a.secondV == ret.secondV) {
        ret.secondCnt += a.secondCnt;
    }

    if (b.firstV == ret.secondV) {
        ret.secondCnt += b.firstCnt;
    }

    if (b.secondV == ret.secondV) {
        ret.secondCnt += b.secondCnt;
    }

    ret.tag1 = INF;
    ret.tag2 = 0;
    return ret;
}

vector <int> vForLCT;

struct LCT {
    int father[N], ch[N][2], isRoot[N], reverse[N];
    Node info[N], val[N];

    void init(const int &n) {
        for (int i = 1; i <= n; i++) {
            isRoot[i] = 1, father[i] = ch[i][0] = ch[i][1] = reverse[i] = 0;
            info[i].init(), val[i] = info[i];
        }
    }

    void up(int i) {
        val[i] = ch[i][0] ? merge(val[ch[i][0]], info[i]) : info[i];
        val[i] = ch[i][1] ? merge(val[i], val[ch[i][1]]) : val[i];
    }

    void down(int i) {
        if (!i) {
            return;
        }

        if (reverse[i]) {
            int lc = ch[i][0], rc = ch[i][1];
            lc ? (swap(ch[lc][0], ch[lc][1]), reverse[lc] ^= 1) : lc;
            rc ? (swap(ch[rc][0], ch[rc][1]), reverse[rc] ^= 1) : rc;
            reverse[i] = 0;
        }

        int lc = ch[i][0], rc = ch[i][1];
        if (val[i].tag1 != INF) {
            int x = val[i].tag1;
            if (lc) {
                val[lc].change(x);
                info[lc].change(x);
            }

            if (rc) {
                val[rc].change(x);
                info[rc].change(x);
            }

            val[i].tag1 = INF;
        }

        if (val[i].tag2 != 0) {
            int x = val[i].tag2;
            if (lc) {
                val[lc].add(x);
                info[lc].add(x);
            }

            if (rc) {
                val[rc].add(x);
                info[rc].add(x);
            }

            val[i].tag2 = 0;
        }
    }

    void rotate(int i) {
        int fa = father[i], fa2 = father[fa];
        int child = (ch[fa][0] == i) ? ch[i][1] : ch[i][0];
        isRoot[i] = isRoot[fa], isRoot[fa] = 0;
        father[i] = fa2, father[fa] = i;
        father[child] = child ? fa : 0;
        if (fa2 && !isRoot[i]) {
            (ch[fa2][0] == fa ? ch[fa2][0] : ch[fa2][1]) = i;
        }

        int t = (i == ch[fa][0]);
        ch[i][t] = fa, ch[fa][t ^ 1] = child;
        up(fa);
    }

    void splay(int x) {
        int now = x;
        vForLCT.clear();
        while (!isRoot[now]) {
            vForLCT.push_back(now), now = father[now];
        }

        down(now);
        for (int i = (int)vForLCT.size() - 1; i >= 0; i--) {
            down(vForLCT[i]);
        }

        while (!isRoot[x]) {
            if (!isRoot[father[x]]) {
                rotate((ch[father[x]][0] == x) == 
                    (ch[father[father[x]]][0] == father[x]) ? father[x] : x);
            }

            rotate(x);
        }

        up(x);
    }

    void expose(int now, const int &type = 0, const int &value = 0) {
        int now2 = 0;
        while (now) {
            splay(now);
            if (!father[now] && type) {
                if (type == 1) {
                    info[now].change(value);
                    if (now2) {
                        val[now2].change(value), info[now2].change(value);
                    }

                    if (ch[now][1]) {
                        val[ch[now][1]].change(value), info[ch[now][1]].change(value);
                    }
                } else if (type == 2) {
                    info[now].add(value);
                    if (now2) {
                        val[now2].add(value), info[now2].add(value);
                    }

                    if (ch[now][1]) {
                        val[ch[now][1]].add(value), info[ch[now][1]].add(value);
                    }
                } else {
                    Node ret = info[now];
                    if (now2) {
                        ret = merge(ret, val[now2]);
                    }

                    if (ch[now][1]) {
                        ret = merge(ret, val[ch[now][1]]);
                    }

                    if (ret.secondV == -INF) {
                        printf("ALL SAME\n");
                    } else {
                        printf("%d %d\n", ret.secondV, ret.secondCnt);
                    }
                }
            }

            isRoot[now2] = 0;
            isRoot[ch[now][1]] = (ch[now][1] > 0);
            ch[now][1] = now2, up(now);
            now2 = now, now = father[now];
        }
    }

    void link(int a, int b) {
        expose(a), splay(a);
        father[a] = b, reverse[a] ^= 1, swap(ch[a][0], ch[a][1]);
    }

    void cut(int a, int b) {
        expose(a), splay(b);
        if (father[b] == a) {
            father[b] = 0;
        } else {
            expose(b), splay(a), father[a] = 0;
        }
    }

    void work(int a, int b, int c, int d) {
        expose(a), expose(b, c, d);
    }

    void ask(int a, int b) {
        expose(a), expose(b, 3, 0);
    }
} t;

int n, q;

void work() {
    scanf("%d %d", &n, &q);
    t.init(n);
    for (int i = 1; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        //printf("%d %d\n", a, b);
        t.link(a, b);
    }

    while (q--) {
        int type, a, b, c, d;
        scanf("%d", &type);
        if (type == 1) {
            scanf("%d %d %d %d", &a, &b, &c, &d);
            t.cut(a, b);
            t.link(c, d);
        } else if (type == 2) {
            scanf("%d %d %d", &a, &b, &c);
            t.work(a, b, 1, c);
        } else if (type == 3) {
            scanf("%d %d %d", &a, &b, &c);
            t.work(a, b, 2, c);
        } else {
            scanf("%d %d", &a, &b);
            t.ask(a, b);
        }
    }
}

int test, tt;

int main() {
    scanf("%d", &test);
    while (test--) {
        printf("Case #%d:\n", ++tt);
        work();
    }

    return 0;
}
