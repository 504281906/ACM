#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<bitset>
#include<string>
#include<cmath>
#include<complex>
#define pb push_back
#define mp make_pair
typedef long long big;
using namespace std;
const int L = 10, r = 6, c = 8;
const int HASHSIZE = 262143;
int id[L][L];
pair<int, int> place[L * L];
int places = 0, nutplace;
int n1, n2, n;
char graph[L][L];
struct node {
    int val;
    int d, nxt;
    int pre;
} q[3000000];
int head[HASHSIZE + 1];
int h, tail;
node S;
int dx[] = { 0, 1, 0, -1 }, dy[] = { 1, 0, -1, 0 };
int getval(int a[]) {
    static int i;
    static int val;
    val = 0;
    for (i = 0; i < n; i++)
        val *= places, val += a[i];
    return val;
}
void clear() {
    memset(id, -1, sizeof(id));
    places = 0;
}
void add(const node &t) {
    static int i, key;
    key = t.val & HASHSIZE;
    for (i = head[key]; i; i = q[i].nxt) {
        if (q[i].val == t.val) {
            return;
        }
    }
    q[++tail] = t;
    q[tail].nxt = head[key];
    head[key] = tail;
}
void init() {
    int i, j;
    int tmp[20];
    place[places++] = mp(0, 0);
    id[0][0] = 0;
    for (i = 1; i <= r; i++)
        for (j = 1; j <= c; j++)
            if (graph[i][j] != 'N' && graph[i][j] != '#') {
                place[places] = mp(i, j);
                id[i][j] = places;
                places++;
            }
    S.val = 0;
    for (i = 1; i <= r; i++) {
        for (j = 1; j <= c; j++)
            if (graph[i][j] == 'S') {
                S.val *= places;
                S.val = id[i][j];
                graph[i][j] = '.';
            }
    }
    n1 = 0;
    for (i = 1; i <= r; i++) {
        for (j = 1; j <= c; j++)
            if (graph[i][j] == 'M') {
                tmp[n1++] = id[i][j];
                graph[i][j] = '.';
            }
    }
    sort(tmp, tmp + n1);
    for (i = 0; i < n1; i++)
        S.val = S.val * places + tmp[i];
    n2 = 0;
    for (i = 1; i <= r; i++) {
        for (j = 1; j <= c; j++)
            if (graph[i][j] == 'P') {
                tmp[n2++] = id[i][j];
                graph[i][j] = '.';
            }
    }
    sort(tmp, tmp + n2);
    for (i = 0; i < n2; i++)
        S.val = S.val * places + tmp[i];

    for (i = 1; i <= r; i++) {
        for (j = 1; j <= c; j++)
            if (graph[i][j] == 'N') {
                nutplace = id[i][j];
            }
    }

    n = n1 + n2 + 1;
}
bool canmove(int x, int y) {
    return x >= 1 && x <= r && y >= 1 && y <= c && graph[x][y] == '.';
}
void move(int type, int &x, int &y, int d) {
    static int k;
    while (canmove(x + dx[d], y + dy[d])) {
        x = x + dx[d];
        y = y + dy[d];
        if (type <= 1) {
            for (k = 0; k < 4; k++)
                if (graph[x + dx[k]][y + dy[k]] == 'P'
                        || graph[x + dx[k]][y + dy[k]] == 'N')
                    return;
        } else if (type == 2) {
            for (k = 0; k < 4; k++)
                if (graph[x + dx[k]][y + dy[k]] == 'S'
                        || graph[x + dx[k]][y + dy[k]] == 'M'
                        || graph[x + dx[k]][y + dy[k]] == 'N')
                    return;
        }
    }
}
void decode(const node &t, int a[]) {
    static int i;
    static int val;
    val = t.val;
    for (i = n - 1; i >= 0; i--)
        a[i] = val % places, val /= places;
}
inline int dist(int place1, int place2) {
    static int x, y;
    x = abs(place[place1].first - place[place2].first);
    y = abs(place[place1].second - place[place2].second);
    return x + y;
}
inline int getx(int place1) {
    return place[place1].first;
}
inline int gety(int place1) {
    return place[place1].second;
}
bool ckwin(const node &t) {
    static int a[L];
    decode(t, a);
    return a[0] && dist(a[0], nutplace) == 1;
}
void getgraph(int a[L]) {
    static int i;
    graph[getx(a[0])][gety(a[0])] = 'S';
    for (i = 1; i <= n1; i++)
        if (a[i])
            graph[getx(a[i])][gety(a[i])] = 'M';
    for (; i < n; i++)
        if (a[i])
            graph[getx(a[i])][gety(a[i])] = 'P';
}
void backgraph(int a[L]) {
    static int i;
    graph[getx(a[0])][gety(a[0])] = '.';
    for (i = 1; i <= n1; i++)
        if (a[i])
            graph[getx(a[i])][gety(a[i])] = '.';
    for (; i < n; i++)
        if (a[i])
            graph[getx(a[i])][gety(a[i])] = '.';
}
bool ckdie(int type, int x, int y) {
    if (type == 2)
        return false;
    static int k;
    for (k = 0; k < 4; k++)
        if (graph[x + dx[k]][y + dy[k]] == 'P')
            return true;
    return false;
}
bool ckeatnut(int x, int y) {
    static int k;
    for (k = 0; k < 4; k++)
        if (graph[x + dx[k]][y + dy[k]] == 'N')
            return true;
    return false;
}
void cpy(int b[], int a[]) {
    static int i;
    for (i = 0; i < n; i++)
        b[i] = a[i];
}
void normalize(int a[]) {
    sort(a + 1, a + 1 + n1);
    sort(a + 1 + n1, a + n);
}
void pri() {
    int i;
    for (i = 1; i <= r; i++)
        puts(graph[i] + 1);
    puts("");
}
int bfs() {
    int i, k, d, a[L], b[L], x, y, xx, yy, dis;
    h = 1;
    tail = 0;
    memset(head, 0, sizeof(head));
    S.d = 0;
    add(S);
    if (ckwin(S))
        return 0;
    node s, v;
    while (h <= tail) {
        s = q[h++];
        dis = s.d;
        decode(s, a);
        x = getx(a[0]);
        y = gety(a[0]);
        getgraph(a);

//        pri();

        for (d = 0; d < 4; d++) {
            cpy(b, a);
            xx = x;
            yy = y;
            move(0, xx, yy, d);
            if (ckdie(0, xx, yy))
                continue;
            else if (ckeatnut(xx, yy)) {
                backgraph(a);
                return dis + 1;
            }
            b[0] = id[xx][yy];
            v.val = getval(b);
            v.d = dis + 1;

            v.pre = h - 1;

            add(v);
        }

        for (i = 1; i <= n1; i++)
            if (a[i]) {
                x = getx(a[i]);
                y = gety(a[i]);
                for (d = 0; d < 4; d++) {
                    xx = x;
                    yy = y;
                    cpy(b, a);
                    move(1, xx, yy, d);
                    if (ckdie(1, xx, yy)) {
                        b[i] = 0;
                    } else if (ckeatnut(xx, yy))
                        continue;
                    else
                        b[i] = id[xx][yy];
                    normalize(b);
                    v.val = getval(b);
                    v.d = dis + 1;

                    v.pre = h - 1;

                    add(v);
                }
            }

        for (i = n1 + 1; i < n; i++) {
            x = getx(a[i]);
            y = gety(a[i]);
            for (d = 0; d < 4; d++) {
                cpy(b, a);
                xx = x;
                yy = y;
                move(2, xx, yy, d);
                if (ckeatnut(xx, yy))
                    continue;
                if (dist(b[0], id[xx][yy]) == 1)
                    continue;
                for (k = 1; k <= n1; k++)
                    if (dist(b[k], id[xx][yy]) == 1)
                        b[k] = 0;
                b[i] = id[xx][yy];
                normalize(b);
                v.val = getval(b);
                v.d = dis + 1;

                v.pre = h - 1;

                add(v);
            }
        }
        backgraph(a);
    }

    return 0x3f3f3f3f;
}
void Print() {
    int i;
    int a[L];
    int stack[200], top = 0;
    for (i = h - 1; i; i = q[i].pre) {
        stack[++top] = i;
    }
    reverse(stack + 1, stack + 1 + top);
    for (i = 1; i <= top; i++) {
        decode(q[stack[i]], a);
        getgraph(a);
        pri();
        backgraph(a);
    }
}
int main() {
    int i, j, k, x, y;
    while (~scanf("%s", graph[1] + 1)) {
        for (i = 2; i <= r; i++)
            scanf("%s", graph[i] + 1);
        clear();
        init();
        printf("%d\n", bfs());
//        Print();
    }
}
