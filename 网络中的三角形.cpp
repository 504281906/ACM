#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
 
int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    int n, m, A, B;
    scanf("%d%d%d%d", &n, &m, &A, &B);
    if(n > m) swap(n, m);
    long long c = 0;
    for(int xx = 1; xx <= n; xx++)
    for(int yy = xx; yy <= m; yy++) {
      long long cc = 0;
      // one corner, no side or diagonal
      for(int x = 1; x < xx; x++) {
        // area2 = xx*yy*2 - (xx-x)*yy - xx*(yy-y) - x*y = (xx-x)*y + (xx*yy*2-(xx-x)*yy-xx*yy)
        int a = xx-x, b = xx*yy*2-(xx-x)*yy-xx*yy; // area2 = ay + b
        int y1 = 1, y2 = yy-1;
        y1 = max(y1, (max(1,A*2)-b-1)/a+1); // ay + b >= max(1,A*2)
        y2 = min(y2, (B*2-b)/a);            // ay + b <= B*2
        if(y1 <= y2) cc += 4 * (y2-y1+1);
      }
      // one diagonal, possibly one side
      for(int x = 0; x <= xx; x++) {
        // area2 = xx*y - x*yy
        int a = xx, b = -x*yy; // area2 = ay + b
        int y1 = 0, y2 = yy;
        y1 = max(y1, (max(1,A*2)-b-1)/a+1); // ay + b >= max(1,A*2)
        y2 = min(y2, (B*2-b)/a);            // ay + b <= B*2
        if(y1 <= y2) cc += 4 * (y2-y1+1);
      }
      // one side, not diagonal
      if(xx*yy >= A*2 && xx*yy <= B*2) cc += (xx + yy - 2) * 2;
 
      c += (long long)(n - xx + 1) * (long long)(m - yy + 1) * cc;
      if(xx != yy && xx <= m && yy <= n) c += (long long)(n - yy + 1) * (long long)(m - xx + 1) * cc;
    }
    cout << c << endl;
  }
  return 0;
}
