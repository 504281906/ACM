#include <cstring>
#include <sstream>
#include <iostream>
using namespace std;
int main()
{
	string s,line;
	while (getline(cin,line))
	{
		istringstream ss(line);
		while (ss>>s)
		cout<<s<<endl;
	}
	return 0;
}
