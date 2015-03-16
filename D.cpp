#include <bits/stdc++.h>
#include <climits>
using namespace std;
#define ll __int64
#define min(a,b) a>b?b:a
int n, m;
ll k;
bool check(ll x)
{
    ll t = 0;
    for (int i = 1; i <= n; ++i)
    {
        ll p = min(x, i * 11l * m);
        t += p / i;
    }
    return t >= k;
}

int main()
{
    cin >> n >> m >> k;
    ll nm = n * m+1;
    ll l = 1;
    ll r = nm;
    while (l < r)
    {
        ll m = (l + r) >> 1;
        if (check(m))
            r = m;
        else
            l = m + 1;
    }
    cout << l << endl;
    return 0;
}
