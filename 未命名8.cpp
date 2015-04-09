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
#include <ctime>
#define LL __int64
#define eps 1e-8
#define pi acos(-1)
using namespace std;
int a[100100],c[50];
char s[100100];
int vis[100010];
int b[100010];
int main(){
	int i,j,k;
	memset(a,0,sizeof(a));
	memset(c,0,sizeof(c));
	for (i=0;i<26;i++)
		scanf("%d",&c[i]);
	getchar();
	scanf("%s",&s);
	int l=strlen(s);
	for (i=0;i<l;i++)
		a[i]=a[i-1]+c[s[i]-'a'];
	int ans=0;
	memset(vis,0,sizeof(vis));
	for (i=0;i<l;i++)
		if (vis[i]==0)
		{
			int t=0;
			b[t++]=i;
		for (j=i+1;j<l;j++)
			if (s[i]==s[j]){
				for (k=0;k<t;k++)
					if (a[j]-a[b[k]]-c[s[i]-'a']==0)
						ans++;
				vis[j]=1;
				b[t++]=j;
			}
		}
	cout<<ans<<endl;
	return 0;
}
