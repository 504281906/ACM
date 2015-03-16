#include <bits/stdc++.h>
using namespace std;
const int M=1e9+7;
__int64 f[10],n;
__int64 mod(__int64 x)
{
	if (x>=0) return x % M;
	else return M+x;
}
int main()
{
	scanf("%I64d%I64d",&f[0],&f[1]);
	//f[0]=mod(f[0]);
	//f[1]=mod(f[1]);
	f[2]=mod(f[1]-f[0]);
	f[3]=mod(0-f[0]);
	f[4]=mod(0-f[1]);
	f[5]=mod(f[0]-f[1]);
	scanf("%I64d",&n);
	printf("%d\n",mod(f[(n-1) % 6]));
	return 0;
}
