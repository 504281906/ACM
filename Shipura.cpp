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
#define N 200010
#define LL __int64
#define M 1000000007
char s[N],ss[N];
stack <LL> num;
stack <LL> go;
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
int main()
{
	freopen("in.txt","r",stdin);
//	freopen("outt.txt","w",stdout);
	while (gets(ss))
	{
		if (ss[0]=='#') break;
		while (!num.empty()) num.pop();
		while (!go.empty()) go.pop();
		LL l=strlen(ss);
		LL tt=0;
		memset(s,0,sizeof(s));
		for (LL i=0;i<l;i++)
		{
			while (ss[i]==' ') i++;
			s[tt++]=ss[i];
		}
		s[tt]='\0';		
		int i=0;
		l=tt;
		while (i<l)
		{
			if (s[i]=='S')
			{
				go.push(0);
				i+=2;
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
				if (!num.empty() && s[i]=='>' && s[i+1]>='0' && s[i+1]<='9')
				{
					LL k=0;
					i++;
					while (s[i]>='0' && s[i]<='9')
					{
						k=(k*10+s[i]-'0') % M;
						i++;
					}
					LL k1=num.top();
					num.pop();
					num.push(ksm(k1,k));
				}
				else
				{
					if (!go.empty() && go.top()==0 && s[i+1]!='S')
					{
						LL k=num.top();
						num.pop();
						k=k % M * k % M;
						num.push(k);
						go.pop();
						while (!go.empty() && go.top()==1)
						{
							k=num.top();
							num.pop();
							LL k1=num.top();
							num.pop();
							num.push(ksm(k1,k));
							go.pop();
						}
					}
					else 
					{
						go.push(1);
						i++;
					}
				}
			}
		}
		LL k;
		k=num.top();
		num.pop();
		cout<<k<<endl;
	}
	return 0;
}
