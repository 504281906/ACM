#include <stdio.h>
#include <string.h>
int A,B,K;
long long f[11][110][110];
long long ff(int x)
{
	int i,j,k,l,s1=0,a[11],s2=0;
	for (i=10;i>=0;i--)
	{
		a[i]=x %10;
		x/=10;
	}
	memset(f,0,sizeof(f)); 
	for (i=0;i<10;i++)
	{ 
		s1=(s1+a[i]) % K;
		s2=(s2*10+a[i]) % K; 
		for (j=0;j<K;j++)
			for (k=0;k<K;k++)
				for (l=0;l<10;l++)
					f[i+1][(j+l) % K][(k*10+l) % K]+=f[i][j][k];
		for (j=0;j<a[i+1];j++)
			++f[i+1][(s1+j)%K][(s2*10+j) % K];
	}
	long long s=f[10][0][0];
	if ((s1+a[10]) % K==0 && (s2*10+a[10]) % K==0) s++;
	return s;
}
int main()
{
	int t; 
	scanf("%d",&t);
	while (t--)	
	{
		scanf("%d%d%d",&A,&B,&K);
		if (K>100) 
			printf("0\n");
		else
			printf("%lld\n",ff(B)-ff(A-1));
	}
	return 0;
}
