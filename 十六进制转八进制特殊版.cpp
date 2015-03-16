#include<bits/stdc++.h>
using namespace std;
int f(char c)
{
	if ('A'<=c)
		return c-'A'+10;
	return c-'0';
}
char s[1000100];
int a[1000100];
int main()
{
	int T;
////	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%d",&T);
	getchar();
	while (T--)
	{
		scanf("%s",s);
		int t=0,w=0,num=0;
		int l=strlen(s);
		for (int i=l-1;i>=0;i--)
		{
			int k=f(s[i]);
			if (t==0)
			{
				a[num++]=k & 7;
				w=k>>3;
				t=(t+1)%3;
			}
			else if (t==1)
			{
				k=(k<<1)+w;
				a[num++]=k & 7;
				w=k>>3;
				t=(t+1)%3;
			}
			else
			{
				k=(k<<2)+w;
				a[num++]=k & 7;
				a[num++]=k>>3;
				w=0;
				t=(t+1)%3;
			}
		}
		if (w) a[num++]=w;
		int j=num-1;
		while (a[j]==0) j--;
		for (int i=j;i>=0;i--)
			printf("%d",a[i]);
		cout<<endl;
	}
	return 0;
}
