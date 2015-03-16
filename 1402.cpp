#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;
int a1[51001],a2[51001],s[90000010],l1,l2;
int l11,l22;
int chengfa()
{
	int pos,i,j;
	memset(s,0,sizeof(s));
	for (i=1;i<=l1;i++)
		for (j=1,pos=i;j<=l2;j++)
			s[pos++]+=a1[i]*a2[j];
	pos-=1;
	for (i=1;i<=pos;i++)
	if (s[i]>=10)
	{
		if (i==pos) pos++;
		s[i+1]+=s[i]/10;
		s[i]%=10;
	}
	return pos;
}
int main()
{
	char s1[1000],s2[1000];
	string ss;
	while (gets(s1),gets(s2))
	{
		l1=strlen(s1);
		l2=strlen(s2);
		if (l1==1 && s1[0]=='0' || l2==1 && s2[0]=='0')
		{
			printf("0\n");
			continue;
		}
		l11=0,l22=0;
		if (s1[0]=='-') l11=1;
		if (s2[0]=='-') l22=1;
		for (int i=l1-1,l=1;i>=l11;i--,l++)
			a1[l]=s1[i]-'0';
		for (int i=l2-1,l=1;i>=l22;i--,l++)
			a2[l]=s2[i]-'0';
		int l=chengfa();
		if (l11!=l22) cout<<'-';
		while (s[l]==0) l--;
		for (int i=l;i>0;i--)
			printf("%d",s[i]);
		printf("\n");
	}
	return 0;
}
