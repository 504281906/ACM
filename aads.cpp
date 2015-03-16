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
char s[10][10];
int main(){
	int i,j;
	for (i=0;i<8;i++)
		scanf("%s",&s[i]);
	int a=0,b=0;
	for (i=0;i<8;i++)
		for (j=0;j<8;j++){
			if (s[i][j]=='Q') a+=9;
			if (s[i][j]=='R') a+=5;
			if (s[i][j]=='B') a+=3;
			if (s[i][j]=='N') a+=3;
			if (s[i][j]=='P') a+=1;
			if (s[i][j]=='q') b+=9;
			if (s[i][j]=='r') b+=5;
			if (s[i][j]=='b') b+=3;
			if (s[i][j]=='n') b+=3;
			if (s[i][j]=='p') b+=1;
		}
	if (a>b) cout<<"White"<<endl;
	else if (a<b) cout<<"Black"<<endl;
	else cout<<"Draw"<<endl;
	return 0;
}
