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
#include <sstream>
#define LL __int64
#define EPS 1e-8
using namespace std;
int main()
{
	double n=100;
	char s[1000];
	sprintf(s,"%lf",n);
	//cout<<s<<endl;
	string a="10000";
	stringstream stream;
	int m=0;
	stream<<a;
	stream>>m;
	cout<<m<<endl;
	stream.clear();
	stream.str("1 2 3.5");
	cout<<stream.str()<<endl;
	int q,w;double e;
	stream>>q;
	cout<<q<<endl;
	stream>>w;
	cout<<w<<endl;
	stream>>e;
	cout<<e<<endl;
	ostringstream ostr;
	ostr.str("abc");
	cout<<ostr.str()<<endl;
//��������ʱ���������ַ�������,��ô����������ʱ�򲻻�ӽ�β��ʼ����, 
//�����޸�ԭ������,�����Ĳ�������
	ostr.put('d');
	ostr<<"efg";
	cout<<ostr.str()<<endl;
	stringstream ss("asd");
	cout<<ss.str()<<endl;
	ss.put('f');
	ss<<"gh";
	cout<<ss.str()<<endl;
	return 0;
}

