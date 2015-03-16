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
using namespace std;
//#define DEBUG
char a='a',b='b';
void swap(char* a,char *b)
{
	char t=*a;
	*a=*b;
	*b=t;
}
int main()
{
#ifdef DEBUG
	freopen("cin.txt", "r", stdin);
	freopen("cout.txt", "w", stdout);
#endif
	int f=1;
	int *c=&f;
	int* d=&f;
	printf("%c %c %d %d %d\n",a,b,c,d,&f);
	(*c)--;
	++c;
	int *h=(int*)2358856;
	//*(int*)2358856=2;
	*h=2;
	printf("%d\n",*(int*)2358856);
	//h=(char*)2358856;
	//*(int*)2358856=0;
	//(*c)++;
	printf("%d\n",h);
	printf("%c %c %d %d %d\n",a,b,c,d,&f);
	swap(&a,&b);
	printf("%c %c %d %d %d\n",a,b,*c,*d,&f);
	return 0;
}
