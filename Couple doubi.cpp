#include <cstdio>
#include <cstdlib>
#include <cstring>
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
#define LL __int64
//#define DEBUG
LL k,p;
int main()
{
    while(scanf("%I64d%I64d",&k,&p)==2)
    {
        LL a=k/(p-1);
        LL b=k%(p-1);
        if(b==0 && a % 2==0) puts("NO");
        else if(b==0 && a % 2==1) puts("YES");
        else if(a % 2==1) puts("YES");
        else puts("NO");
    }
	return 0;
}
/*#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
#include <map>
#include <stack>
#include <list>
#include <vector>
using namespace std;
#define LL __int64
//#define DEBUG
LL n,m;
int main()
{
	while (~scanf("%I64d%I64d",&n,&m))
	{
		if (m>3) puts("NO");
		else
		{
			if (m==3) 
				if (n % 4==0 || n % 4==1) puts("NO");
				else puts("YES");
			else 
				if (n % 2==0) puts("NO");
				else puts("YES");
		}
	}
	return 0;
}*/
