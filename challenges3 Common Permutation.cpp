#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
char s1[110],s2[110];
bool cmp(char a,char b)
{
	return a<b;
}
int main()
{
	string s1,s2;
	while (getline(cin,s1)!=NULL && getline(cin,s2)!=NULL)
	{
		sort(&s1[0],&s1[0]+s1.length(),cmp);
		sort(&s2[0],&s2[0]+s2.length(),cmp);
		int i=0,j=0;
		while (s1[i]!='\0' && s2[j]!='\0')
		{
			if (s1[i]==s2[j])
			{
				printf("%c",s1[i]);
				i++;
				j++;
			}
			else if (s1[i]<s2[j]) i++;
			else j++;
		}
		printf("\n");
	}
	return 0;
}
