#include<stdio.h>
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s1="dsa";
	string ch="123456";
	s1.append(ch);
	cout<<s1<<endl;
	s1.append(ch,0,3);
	cout<<s1<<endl;
	string s;
	s.append(1,(char)(1+'0'));
	cout<<s<<endl;
}
