#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
#include <map>
#include <stack>
#include <list>
#include <vector>
#include <assert.h>
#include <ctype.h>
using namespace std;
//#define DEBUG
int main()
{
#ifdef DEBUG
	freopen("cin.txt", "r", stdin);
	freopen("cout.txt", "w", stdout);
#endif
	char s[1000];
	fgets(s,sizeof(s),stdin);
	int l=strlen(s);
	for (int i=0;i<l;i++)
		if (isalpha(s[i])) printf("%c",toupper(s[i]));
	printf("\n");
	return 0;
}

