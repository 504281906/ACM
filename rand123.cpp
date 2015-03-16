#include <iostream>
#include <cstdio>
#include <ctime>
#include <algorithm>
using namespace std;
int main()
{
	int a;
	srand((unsigned) time(NULL));
	while (1)
	{
		cout<<rand()%10+1<<endl;
		system("pause");
	}
}
