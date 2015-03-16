#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <cassert>
using namespace std;
#define ALL(v) (v).begin(), (v).end()
#define SZ(v) (int)((v).size())
#define FOR(i, a, b) for(__typeof(a) i = (a); i < (b); i++)
#define CLEAR(a, b) memset((a), (b), sizeof(a))
const int N = 2048;
set<int> unmalt[N];
int malt[N], label[N];
set<int> test[N];
bool go(int);
int main()
{
int T;
scanf("%d", &T);
FOR(t, 0, T) {
   int n, m; scanf("%d %d", &n, &m);
   CLEAR(malt, -1);
   FOR(i, 0, m) {
    unmalt[i].clear();
    int c; scanf("%d", &c);
    FOR(j, 0, c) {
     int x, y; scanf("%d %d", &x, &y); x--;
     if(y == 0) unmalt[i].insert(x);
     else malt[i] = x;
    }
    test[i] = unmalt[i];
   }
   bool can = go(m);
   printf("Case #%d:", t+1);
   if(can) FOR(i, 0, n) printf(" %d", label[i]);
   else printf(" IMPOSSIBLE");
   printf("\n");
}
return 0;
}
bool go(int n)
{
	CLEAR(label, 0);
	queue<int> Q;
	FOR(i, 0, n) if(SZ(unmalt[i]) == 0 && label[malt[i]] == 0)
   { Q.push(malt[i]); label[malt[i]] = 1; }
	while(!Q.empty()) {
   int p = Q.front(); Q.pop();
   FOR(i, 0, n) if(unmalt[i].count(p)) {
    unmalt[i].erase(p);
    if(SZ(unmalt[i]) != 0) continue;
    if(malt[i] == -1) return false;
    else if(label[malt[i]] == 0) { Q.push(malt[i]); label[malt[i]] = 1; }
   }
}
return true;
}
