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
int main()
{
	int T,i,k;
	char s[110];
	scanf("%d",&T);
	getchar();
	while (T--)
	{
		k=0;
		stack <char> st;
		//st.clear();
		while (!st.empty()) st.pop();
		gets(s);
		int l=strlen(s);
		for (i=0;i<l;i++)
		{
			if (s[i]==')' || s[i]==']')
			{
				if (st.empty()) 
				{
					k++;
					continue;
				}
				char c=st.top();
				if ( (c=='(' && s[i]==')') || (c=='[' && s[i]==']') ) 
				{
					st.pop();
					continue;
				}
				else 
				{
					char ss[110];
					int j=0;
					while (!st.empty())
					{
						ss[j++]=st.top();
						st.pop();
					}
					int jj,f=0;
					for (jj=0;jj<j;jj++)
						if ((ss[jj]=='(' && s[i]==')') || (ss[jj]=='[' && s[i]==']')) 
						{
							f=1;
							break;
						}
					if (f) k+=jj;
					else 
					{
						jj=-1;
						k++;
					}
					int jjj;
					for (jjj=j-1;jjj>jj;jjj--)
						st.push(ss[jjj]);
				}
			}
			else st.push(s[i]);
		}
		while (!st.empty()) 
		{
			k++;
			st.pop();
		}
		printf("%d\n",k);
	}
	return 0;
}
