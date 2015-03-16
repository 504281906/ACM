#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    int str[50];
    for (int i=0;i<3;i++)
    	scanf("%d",&str[i]);
    sort(str, str+3);
    
    int i=1;
    while (next_permutation(str, str+3))
    {
    	i++;
        for (int i=0;i<3;i++)
        	printf("%d ",str[i]);
        cout<<endl;
    }
    cout<<i<<endl;
    return 0;
}
