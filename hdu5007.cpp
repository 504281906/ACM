#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <stack>
#include <cassert>
using namespace std;

typedef long long LL;

char str[7];

void work() {
    char c;
    while (c = getchar() , ~c) {
        for (int i = 0 ; i < 5 ; ++ i)
            str[i] = str[i + 1];
        str[5] = c;
        if (!strcmp(str , "iPhone"))
            puts("MAI MAI MAI!");
        if (!strcmp(str + 2 , "iPad"))
            puts("MAI MAI MAI!");
        if (!strcmp(str + 2,  "iPod"))
            puts("MAI MAI MAI!");
        if (!strcmp(str + 1 , "Apple"))
            puts("MAI MAI MAI!");
        if (!strcmp(str + 2 , "Sony"))
            puts("SONY DAFA IS GOOD!");
    }
}

int main() {
        work();
    return 0;
}
