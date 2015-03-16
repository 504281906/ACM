#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
struct trie
{
	trie * son[30];
	int v[30];
	trie()
	{
		for (int i=0;i<30;i++)
		{	
			son[i]=NULL;
			v[i]=0;
		}
	}
}*root;
int t,n;
char s[30];
void insert(trie * rt,int l)
{
	for (int i=0;i<l;i++)
	{
		int c=s[i]-'a';
		if (rt->son[c]==NULL)
		{
			trie *rit=new trie();
			rt->son[c]=rit;
			rt->son[c]->v[c]=1;
		}
		else rt->son[c]->v[c]++;
		rt=rt->son[c];
	}
}
int getans(trie * rt,int l)
{
	int ans=0;
	for (int i=0;i<l;i++)
	{
		int c=s[i]-'a';
		if (rt->son[c]==NULL) return 0;
		else ans=rt->son[c]->v[c];
		rt=rt->son[c];
	}
	return ans;
}
/*void del(trie * root)
{
	for(int i=0;i<30;i++)
    {
        if(root->son[i]!=NULL)
            del(root->son[i]);
    }
    free(root);
}*/
int main()
{
	scanf("%d",&n);
	t=0;
	root=new trie();
	getchar();
	for (int i=0;i<n;i++)
	{
		scanf("%s",&s);
		int l=strlen(s);
		insert(root,l);
	}
	scanf("%d",&n);
	getchar();
	for (int i=0;i<n;i++)
	{
		scanf("%s",&s);
		int l=strlen(s);
		printf("%d\n",getans(root,l));
	}
	delete root;
   // del(root);
	return 0;
}
