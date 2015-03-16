#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int n;

const int N = 40;

char sym[N];
unsigned int num[N];

inline unsigned int trans(char ch) {
    if (ch >= '0' && ch <= '9') {
        return ch - '0';
    } else {
        return ch - 'a' + 10;
    }
}

unsigned int getNum(char *s) {
    unsigned int ret = 0;
    for (int i = 0; i < 8; ++i) {
        ret = ret << 4 | trans(s[i]);
    }
    return ret;
}

int stamp, vis[1 << 20], qhead, qtail, qtail2;
unsigned int best[2][1 << 20], q[2][1 << 20];

int b[N];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        {
            int tot = 0;
            char op[3], buf[10];
            for (int i = 0; i < n; ++i) {
                scanf("%s%s", op, buf);
                unsigned int x = getNum(buf);
                if (op[0] == '-') {
                    op[0] = '+';
                    x = (~x) + 1;
                }
                if (tot && sym[tot - 1] == '+' && op[0] == '+') {
                    num[tot - 1] += x;
                } else {
                    sym[tot] = op[0];
                    num[tot] = x;
                    ++tot;
                }
            }
            n = tot;
        }
        {
            qhead = 0, qtail = 1;
            q[0][qhead] = 0;
            best[0][0] = 0;
        }
        int now = 0;
        for (int bit = 0; bit < 32; ++bit) {
            for (int i = 0; i < n; ++i) {
                b[i] = num[i] >> bit & 1;
            }
            int next = now ^ 1;
            qtail2 = 0;
            ++stamp;
            while (qhead < qtail) {
                int st = q[now][qhead++];
                for (int c = 0; c < 2; ++c) {
                    unsigned cur = c; 
                    int nst = 0, cnt = 0;
                    for (int i = 0; i < n; ++i) {
                        if (sym[i] == '+') {
                            cur += b[i] + (st >> cnt & 1);
                            if (cur & 2) {
                                nst |= 1 << cnt;
                                cur ^= 2;
                            }
                            ++cnt;
                        } else {
                            if (sym[i] == '&') {
                                cur &= b[i];
                            } else if (sym[i] == '|') {
                                cur |= b[i];
                            } else {
                                cur ^= b[i];
                            }
                        }
                    }
                    if (vis[nst] != stamp) {
                        vis[nst] = stamp;
                        best[next][nst] = 0;
                        q[next][qtail2] = nst;
                        ++qtail2;
                    }
                    best[next][nst] = max(best[next][nst], (best[now][st] | (cur << bit)));
                }
            }
            now = next;
            qhead = 0, qtail = qtail2;
        }
        unsigned int ans = 0;
        for (int qhead = 0; qhead < qtail; ++qhead) {
            ans = max(ans, best[now][q[now][qhead]]);
        }
        printf("%u\n", ans);
    }
    return 0;
}
