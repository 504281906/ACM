#include<bits/stdc++.h>
int a[30],a1[30];
char s[1100],t[1100];
int main()
{
	int i;
	gets(s);
	gets(t);
	if (strstr(s,t)!=NULL) puts("automaton");
	else if (strlen(s)==strlen(t))
	{
		int l=strlen(s);
		memset(a,0,sizeof(a));
		for (i=0;i<l;i++)
			a[s[i]-'a']++;
		for (i=0;i<l;i++)
			a[t[i]-'a']--;
		int f=0;
		for (i=0;i<26;i++)
		if (a[i]!=0) 
		{
			f=1;
			break;
		}
		if (f==0) puts("array");
		else puts("need tree");
	}
	else
	{
		memset(a,0,sizeof(a)); //tµÄ×Ö·û 
		memset(a1,0,sizeof(a1));
		int l1=strlen(s);
		int l2=strlen(t);
		for (i=0;i<l2;i++)
			a[t[i]-'a']++;
		for (i=0;i<l1;i++)
			a1[s[i]-'a']++;
		int f=0;
		for (i=0;i<26;i++)
		if (a[i]!=0 && a[i]>a1[i])
			{
				f=1;
				break;
			}
		if (f==0) 
		{
			i=0;
			int j=0,h=0;;
			while (i<l1)
			{
				while (i<l1)
				{
					
					if (t[j]==s[i])
					{
						i++;
						j++;
						break;
					}
					i++;
					
				}
				if (j==l2)
				{
					h=1;
					break;
				}
			}
			if (h) puts("automaton");
			else
			puts("both");
		}
		else puts("need tree");
	}
	return 0;
}
