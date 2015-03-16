#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <time.h>
using namespace std;
int main()
{
	//Random rand=new Random(2);
	time_t time1;
	while(1)
	{
		time1=time(NULL);
		cout<<time1<<endl;
		srand(time(NULL));
		int i=rand()%1000;
		cout<<i<<endl;
		system("pause");
	}
} 
