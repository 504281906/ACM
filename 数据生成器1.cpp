#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
#include <map>
#include <stack>
#include <list>
#include <vector>
#include <ctime>
using namespace std;
#define LL __int64
void ex_gcd(LL a, LL b, LL &x, LL &y, LL &d)
{
    if (!b)
        x = 1, y = 0, d = a;
    else
    {
        ex_gcd(b, a % b, y, x, d);
        y -= x * (a / b);
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    srand(time(NULL));
    while (T--)
    {
        LL n1, n2, f1, f2, d1, d2;
        LL a, b, v, x, y, dx, dy, gcd, lcm;
        n1=rand()%100;
        f1=rand()%10+1;
        d1=rand()%10+1;
        n2=rand()%100;
        f2=rand()%10+1;
        d2=rand()%10+1;
        cout<<n1<<" "<<f1<<" "<<d1<<" "<<n2<<" "<<f2<<" "<<d2<<endl;
        /*//cin>>n1>>f1>>d1>>n2>>f2>>d2;
        a = d1, b = -d2, v = d1 - d2 + f2 - f1;
        ex_gcd(a, b, x, y, gcd);
       // cout<<x<<" "<<y<<endl;
        lcm = abs(d1 * d2 / gcd);
            x *= v / gcd;
            x = f1 + (x - 1) * d1;
            dx = abs(b / gcd * d1);
            dy = abs(a / gcd);
            LL l = max(f1, f2);
            x = ((x - l) % dx + dx) % dx + l;
            y = (x - f2) / d2 + 1;
            x = (x - f1) / d1 + 1;
            dx /= d1;
            y = min((n1 - x) / dx, (n2 - y) / dy) + 1;*/
    }
    return 0;
}
