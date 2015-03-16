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
#define N 20000010
#define LL long long
#define M 1000000007
char s[N];
stack <LL> num;
stack <int> go;
LL ksm(LL a,LL b)
{
	if (b==0) return a;
	for (int i=1;i<=b;i++)
	{
		a/=2;
		if (a==0) return 0;
	}
	return a;
}
void solve()
{
	while (!go.empty())
	{
		if (go.top()==1)
		{
			LL k=num.top();
			num.pop();
			LL k1=num.top();
			num.pop();
			num.push(ksm(k1,k));
		}
		else
		{
			LL k=num.top();
			num.pop();
			k=k * k % M;
			num.push(k);	
		}
		go.pop();
	}
	return;
}
int main()
{
	while (gets(s) && strstr(s,"#")==NULL)
	{
		while (!num.empty()) num.pop();
		while (!go.empty()) go.pop();
		LL l=strlen(s);
		for (LL i=0;i<l;i++)
		if (s[i]==' ')
		{
			LL j=i;
			while (s[j]==' ') j++;
			for (LL k=j;k<l;k++)
				s[i+k-j]=s[k];
			l=l+i-j;
			s[l]='\0';
		}
		LL i=0;
		while (i<l)
		{
			if (s[i]=='S')
			{
				i=i+2;
				go.push(0);
			}
			if (s[i]>='0' && s[i]<='9')
			{
				LL k=0;
				while (s[i]>='0' && s[i]<='9')
				{
					k=(k*10+s[i]-'0') % M;
					i++;
				}
				num.push(k);
			}
			if (s[i]=='>')
			{
				i++;
				if (s[i]=='>' && (s[i+1]=='S' || s[i+1]>='0' && s[i+1]<='9'))
				{
					i++;
					LL k=0;
					while (s[i]>='0' && s[i]<='9')
					{
						k=(k*10+s[i]-'0') % M;
						i++;
					}
					go.push(1);
					num.push(k);
					solve();
				}
				else if (go.top()==0)	
					solve();
				else
				{
					if (s[i]=='>')
					{
						go.push(1);
						i++;
					}
				}
			}
		}
		solve();
		LL k=num.top();
		printf("%lld\n",k);
	}
	return 0;
}
