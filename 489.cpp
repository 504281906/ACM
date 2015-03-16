#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <string>
using namespace std;

#define ff(i, n) for(int i=0;i<(n);i++)
#define fff(i, n, m) for(int i=(n);i<=(m);i++)
#define dff(i, n, m) for(int i=(n);i>=(m);i--)
typedef long long LL;
typedef unsigned long long ULL;
void work();

int main()
{
#ifdef ACM
    freopen("in.txt", "r", stdin);
#endif // ACM

    work();
}

/***************************************************/

const int mod = 1000000009;

int powMod(LL a, int b)
{
    LL res = 1;
    while(b)
    {
        if(b&1)
            res = res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}

int inv[111111];

void work()
{
    // 初始化，求出1-100000在模1000000009系下的逆元
    fff(i, 1, 100000)
        inv[i] = powMod(i, mod-2);

    int n, m;
    while(~scanf("%d%d", &n, &m))
    {
        int l = 0, r = 0;
        int ll, rr;

        ff(i, n)
        {
            int x;
            scanf("%d", &x);

            if(r + x <= m)
                rr = r + x;
            else if(l + x <= m)
                rr = ((m + l + x)&1) ? m-1 : m;
            else
                rr = 2 * m - l - x;

            if(l - x >= 0)
                ll = l - x;
            else if(r - x >= 0)
                ll = ((l + x)&1);
            else
                ll = x - r;

            l = ll, r = rr;
        }

        LL ans = 0;

        LL c = 1;
        fff(i, 0, m)
        {
            if(i == l)
            {
                ans += c;
                l += 2;
                if(l > r) break;
            }

            c = c * (m-i) % mod * inv[i+1] % mod;
        }

        printf("%I64d\n", ans%mod);
    }
}
