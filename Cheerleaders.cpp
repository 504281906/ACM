#include <stdio.h>
#include <string.h>
const int mod=1000007; 
int a[510][510];
int main()
{
	int t,n,m,k;
	memset(a,0,sizeof(0));
	for (int i=0;i<=500;i++) //这里有用到数学里的组合公式 
	{
		a[i][i]=a[i][0]=1;
		for (int j=1;j<i;j++)
			a[i][j]=(a[i-1][j]+a[i-1][j-1]) % mod; 
	}
	scanf("%d",&t);
	for (int i=1;i<=t;i++)
	{
		scanf("%d%d%d",&n,&m,&k);
		int s=0;
		for (int j=0;j<16;j++)  //这里有用到容斥定理和位运算
		{ 
			int h=n,l=m,f=0;  //h代表行，l代表列，s代表方法总数，f判断满足几次 
			if (j&1){h--;f++;}
			if (j&2){h--;f++;}
			if (j&4){l--;f++;}
			if (j&8){l--;f++;}
			if (f&1) s=(s+mod-a[h*l][k]) % mod;
				else s=(s+a[h*l][k]) % mod;
		}
		printf("Case %d: %d\n",i,s); 
	} 
	return 0;
}
