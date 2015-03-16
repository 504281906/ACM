#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	char a[10010];
	int f[10010];
	while (~scanf("%s",&a))
	{
		int l=strlen(a);
		int k=0;
		int t=0;
		int i=0;
		while (a[i]=='5') i++;
		while (i<l)
		{
			if (a[i]=='5')
			{
				f[t]=k;
				k=0;
				t++;
				while (a[i]=='5') i++;				
			}
			else
			{
				k=k*10+a[i]-'0';
				i++;
			}
		}
		if (k) 
		{f[t]=k;
			t+=1;
		}
		sort(f,f+t);
		printf("%d",f[0]);
		for (i=1;i<t;i++)
			printf(" %d",f[i]);
		cout<<endl;
	}
	return 0;
}

