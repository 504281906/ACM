 
#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<cstdio>
using namespace std;

struct sStack
{
	char sign[10010];
	int top;
};

void initstack(sStack &s)
{
	s.top = -1;
}

bool isemptystack(sStack &s)
{
	return s.top == -1 ? 1 : 0;
}

int pushstack(sStack &s, char c)
{
	s.sign[++s.top] = c;
	return 1;
}

int popstack(sStack &s)
{
	if(isemptystack(s))
		return 0;
	s.top--;
	return 1;
}

char topstack(sStack &s)
{
	if(isemptystack(s))
		return 0;
	return s.sign[s.top];
}

int main()
{
	int N, len, i;
	bool flag;
	char str[10010];
	sStack s;
	scanf("%d", &N);
	while(N--)
	{
		flag = 1;
		scanf("%s", str);
		len = strlen(str);
		initstack(s);
		for(i = 0; i < len; ++i)
		{
			if(str[i] == '(' || str[i] == '[' || str[i] == '{')
				pushstack(s, str[i]);
			else if(str[i] == ')')
			{
				if(isemptystack(s) || topstack(s) != '(')	flag = 0;
				else	popstack(s);
			}
			else if(str[i] == ']')
			{
				if(isemptystack(s) || topstack(s) != '[')	flag = 0;
				else	popstack(s);
			}
			else if(str[i] == '}')
			{
				if(isemptystack(s) || topstack(s) != '{')	flag = 0;
				else	popstack(s);
			}
		}
		if(!isemptystack(s)) {flag = 0;}
		if(flag)	printf("Yes\n");
		else	printf("No\n");
	}
	return 0;
}
