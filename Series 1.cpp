#include<vector>
#include<list>
#include<map>
#include<set>
#include<deque>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<ctime>
#define LL long long
using namespace std;
LL a[4000];
int main(){
  int t;
  scanf("%d",&t);
  while(t--)
  {
    int n ;
    scanf("%d",&n);
    for(int i = 1;i <= n;i ++)
    scanf("%I64d",&a[i]);
    while(--n)
    {
        for(int i = 1;i <= n;i ++)
            a[i] = a[i+1] - a[i];
    }
    printf("%I64d\n",a[1]);
  }
return 0;
}
