#include <cstdio>
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
//#define DEBUG
//#define max(a,b) a>b?a:b
struct bign
{
	int len,s[1000];
	bign() 
	{
		memset(s,0,sizeof(s));
		len=1;
	}
	bign(const char* num) { *this=num; }
	bign operator = (const char* num)
	{
		len = strlen(num);
		for (int i=0; i<len; i++)
			s[i] = num[len-i-1] - '0';
		return *this;
	}
	bign operator + (const bign &b) const 
	{
		bign c;
		c.len=0;
		int k=max(len,b.len);
		for (int i = 0,g = 0; g || i<k; i++)
		{
			int x=g;
			if (i < len) x+=s[i];
			if (i <b.len) x+=b.s[i];
			c.s[c.len++] = x % 10;
			g = x / 10;

		}
		return c;
	}
};
int main()
{
#ifdef DEBUG
	freopen("cin.txt", "r", stdin);
	freopen("cout.txt", "w", stdout);
#endif
	bign x,x1;
	char ch[1000],ch1[1000];
	gets(ch);gets(ch1);
	x=ch;x1=ch1;
	bign y;
	y=x+x1;
	for (int i=y.len-1; i>=0; i--)
		printf("%d",y.s[i]);
	cout<<endl;
	return 0;
}
