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
using namespace std;
int findFirstGreaterThanOrEqual(int array[], int N, int X)
{
	int start = 0, end = N;
	while (start < end) 
	{
		int middle = (start + end) / 2;
		if (array[middle] > X)	end = middle;
		else 	start = middle + 1;
	}
	return start;
}
int main()
{
	scanf
	return 0;
}

