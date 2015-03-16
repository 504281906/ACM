#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
	char c;
	int n,i,m,j;
	int T=0;
	while (~scanf("%c %d",&c,&n) && c!='@')
	{
		getchar();
		m=2*n-1;
		if (T) cout<<endl;
		T++;
		for (i=1;i<n;i++)
		{
			for (j=1;j<=(m-i*2+1)/2;j++)
				printf(" ");
			printf("%c",c);
			for (j=1;j<=(i-1)*2-1;j++)
				printf(" ");
			if (i!=1) printf("%c",c);
			printf("\n");
		}
		for (i=1;i<=m;i++)
			printf("%c",c);
		printf("\n");
	}
	return 0;
}

