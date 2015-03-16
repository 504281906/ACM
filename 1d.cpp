#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std ;

const int MAXN = 1e6+10;

int n,m;
int a[MAXN];
int left[MAXN],right[MAXN];
map<int,int> number,number2;
int c[MAXN];

void update(int pos,int v){
    while (pos<=n){
        c[pos] += v;
        pos += pos & - pos;
    }
}
int query(int pos){
    int ret=0;
    while (pos>0){
        ret += c[pos] ;
        pos -= pos & -pos;
    }
    return ret;
}

int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=n;i++){
        number[a[i]]++;
        left[i]=number[a[i]];
    }
    for (int i=n;i>=1;i--)
    {
        number2[a[i]]++;
        right[i]=number2[a[i]];
    }
    for (int i=n;i>=1;i--) update(right[i],1);
    long long res=0;
    for (int i=1;i<=n;i++){
        update(right[i],-1);
        res+=query(left[i]-1);
    }
    printf("%I64d\n",res);
    return 0;
}
