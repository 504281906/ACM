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
int main(){
	int i,j;
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
	for (i=0;i<l-1;i++)
		if (s[i]==s[i+1]) ans++;
	for (i=0;i<l;i++)
		for (j=i+2;j<l;j++)
			if (s[i]==s[j] && a[j]-a[i]-c[s[i]-'a']==0)
				ans++;
	cout<<ans<<endl;
	return 0;
}
