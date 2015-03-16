typedef unsigned long long LLong;
typedef long double LDb;
long long n,m,k;
long long rec(long long q) {
    long long res = 0;
    for (int i = 1; i <= n; ++i) {
        long long w = q/i;
        if (w>m)
            w = m;
        res += w;
    }
    return res;
}

int main()
{
#ifdef m0stik
    freopen("input.txt","r",stdin);
#else
    //freopen("river.in","r",stdin);
    //freopen("river.out","w",stdout);
#endif
    cin >> n >> m >> k;
    long long l = 0;
    long long r = 1000000000000000000LL;
    while (l+1<r) {
        long long m = (l+r)>>1;
        long long q = rec(m);
        //cout << "M: " << m << "; q= " << q << endl;
        if (q<k) {
            l = m;
        }
        else {
            r = m;
        }
    }
    cout << r << endl;
    return 0;
} 
