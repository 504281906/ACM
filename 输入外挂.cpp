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
#define LL __int64
#define EPS 1e-8
using namespace std;
int Scan()
{
	int flag=0,ret=0,c;
	if ((c=getchar())=='-')
		flag=1;
	else if (c>='0' && c<='9')
		ret=c-'0';
	while ((c=getchar())>='0' && c<='9')
		ret=ret*10+(c-'0');
	return flag?-ret:ret;
}
int main()
{
	int a=Scan(); 
	cout<<a<<endl;
	return 0;
}
//思路很简单：
//第一步：先判断当前字符是不是'-'号，如果是，
//flag标记为1（表示该整数是负数）；否则，弱该字符是数字，则取出该数字。
//第二步：得到完整的数，只要是连续的数字，就一直累乘。
//第三步：根据flag的值返回该整数的值
