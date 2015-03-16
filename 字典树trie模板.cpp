#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
struct trie
{
	trie * son[26];
	int v;
	trie()
	{
		for (int i=0;i<26;i++)
			son[i]=NULL;v=0;	
	}
}*root,k[1000010];
int t=0;
char a[1000010];
void insert(trie *rt,int l)
{
	for (int i=0;i<l;i++)
	{
		int c=a[i]-'a';
		if (rt->son[c]==NULL)
		{
			k[++t]=trie();
			rt->son[c]=&k[t];
			rt->son[c]->v=l-1-i;
		}
		else
		if (rt->son[c]->v>l-1-i)
			rt->son[c]->v=l-1-i;
		rt=rt->son[c];
	}
}
int getanswer(trie * rt,int l)
{
	int ans=l;
	for (int i=0;i<l;i++)
	{
		int c=a[i]-'a';
		if (rt->son[c]==NULL) break;
		else
		{
			if (ans>rt->son[c]->v+l-i)
				ans=rt->son[c]->v+l-i;
		}
		rt=rt->son[c];
	}
	return ans;
}
int main()
{
	int T,n;
	scanf("%d",&T);
	while (T--)
	{
		t=-1;
		scanf("%d %s",&n,a);
		k[++t]=trie();
		root=&k[t];
		int l=strlen(a);
		insert(root,l);
		while (n--)
		{
			scanf("%s",a);
			l=strlen(a);
			int ans=getanswer(root,l);
			insert(root,l);
			printf("%d\n",ans);
		}
	}
	return 0;
}
