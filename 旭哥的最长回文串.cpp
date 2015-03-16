#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 110005;
char str[N], cpy[N<<1];
int seq[N<<1];

void manacher(char s[], int length, int rad[]) 
{
    for (int i=1,j=0,k; i < length; i+=k) 
	{
        while (s[i-j-1] == s[i+j+1]) ++j;
        rad[i] = j;
        for (k = 1; k <= rad[i] && rad[i-k] != rad[i]-k; ++k) 
		{ 
			// 利用类似镜像的方法缩短了时间 
            rad[i+k] = min(rad[i-k], rad[i]-k);
        }
        j = max(j-k, 0);
    }
}

int main() 
{
    while (scanf("%s", str) != EOF) 
	{
        int len = strlen(str);
        cpy[0] = '(', cpy[1] = '#';
        for (int i=0, j=2; i < len; ++i, j+=2) {
            cpy[j] = str[i];
            cpy[j+1] = '#';
        }
        len = len*2+3;
        cpy[len-1] = ')';
        manacher(cpy, len, seq);
        int Max = 1;
        for (int i = 0; i < len; ++i) {
            Max = max(Max, seq[i]);
        }
        printf("%d\n", Max);
    }
    return 0;
}
