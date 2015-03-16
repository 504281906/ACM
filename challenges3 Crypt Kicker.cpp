#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const char c[50]={"the quick brown fox jumps over the lazy dog"};
int main()
{
	string s[110];
	int T;
	scanf("%d",&T);
	getchar();
	getline(cin,s[0]);
	while (T--)
	{
		char mw[30]={"***************************"};
		int k=0;
		int l=strlen(c);
		while (getline(cin,s[k])!=NULL && s[k].length()>0)
		{
			if (s[k].length()==l)
			{
				char c1[50];
				strcpy(c1,mw);
				for (int i=0;i<l;i++)
				{
					if (c[i]==' ' && s[k][i]==' ') continue;
					if ((c[i]==' ' && s[k][i]!=' ') || (c[i]!=' ' && s[k][i]==' '))
					{	
						strcpy(mw,c1);
						break;
					}
					if (mw[s[k][i]-'a']=='*' || mw[s[k][i]-'a']==c[i])
							mw[s[k][i]-'a']=c[i];
					else
					{
						strcpy(mw,c1);
						break;
					}
				}
			}
			k++;
		}
		bool f=true;
		for (int i=0;i<26;i++)
		if (mw[i]=='*') 
		{
			f=false;
			printf("No solution.\n");
			break;
		}
		if (f)
		for (int i=0;i<k;i++)
		{
			for (int j=0;j<s[i].length();j++)
			{
				if (s[i][j]==' ') 
					printf(" ");
				else 
					printf("%c",mw[s[i][j]-'a']);
			}
			printf("\n");
		}
		if (T) printf("\n");
	} 
	return 0;
} 
