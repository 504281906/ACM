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
using namespace std;
#define LL __int64
int main()
{
    int T,n,m,k;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d%d",&n,&m,&k);
        if (k>n) cout<<"NO"<<endl;
        else
        if (n % m==k || (n%m==0 && m==k)) cout<<"YES"<<endl;
        else  cout<<"NO"<<endl;
    }
    return 0;
}
