#include <cstdio>
#include <iostream>
#include <map>
#include <cstring>
using namespace std;
char s[2010];
char a[2010];
char b[2010];
int main()
{
	int T;
	scanf("%d",&T);
	map<string,int>mm;
	mm.clear();
	while (T--)
	{
		getchar();
		gets(s);
		int n;
		scanf("%d",&n);
		while(n--)
		{
			map<string,int> m;
			m.clear();
			int begin,end;
			scanf("%d%d",&begin,&end);
			int k,i,j;
			memset(a,0,sizeof(a));
			memset(b,0,sizeof(b));
			for (k=0,i=begin-1;i<end;k++,i++)
				b[k]=s[i];
			int q=0,f=1;a[0]='a';
			for (i=1;i<k;i++)
			{
				bool flag=true;
				for (j=0;j<i;j++)
					if (b[i]==b[j]) {a[i]=a[j];flag=false;break;}
				if (flag) {a[i]='a'+f;f++;}
			}
			if (mm[a]!=0) printf("%d\n",mm[a]);
			else
			{
			int l=end-begin+1;
			int t=0;
			for (i=1;i<=l;i++)
				for (j=0;j<k-i+1;j++)
				{
					string ss="";
					for (int jj=j;jj<i+j;jj++)
						ss+=a[jj];
				if (m[ss]==0) t++;
				m[ss]=1;
				}
			printf("%d\n",t);
			mm[a]=t;
			}
		} 
	}
	return 0;
}
