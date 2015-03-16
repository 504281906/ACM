#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
struct trie
{
	trie *son[26];
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
	int ans=1;
	for (int i=0;i<l;i++)
	{
		int c=a[i]-'a';
		if (rt->son[c]==NULL) break;
		else
		{
			ans++;
			if (i==l-1) ans--;
			//if (ans>rt->son[c]->v+l-i)
			//	ans=rt->son[c]->v+l-i;
		}
		rt=rt->son[c];
	}
	return ans;
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int T,n;
	scanf("%d",&T);
	int cas=1;
	while (T--)
	{
		t=-1;
		scanf("%d",&n);
		k[++t]=trie();
		root=&k[t];
		int l;
		int ans=0;
		while (n--)
		{
			scanf("%s",a);
			l=strlen(a);
			ans+=getanswer(root,l);
			insert(root,l);	
		}
		printf("Case #%d: %d\n",cas++,ans);
	}
	return 0;
}
