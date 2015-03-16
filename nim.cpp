#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<limits.h>
#include <iostream>
using namespace std;
__int64 m[111111],x[111111];
int f(__int64 a,__int64 b)
{
	long long ans=0;
	if(b%2!=0)
	{
		if(a%2==0)
			ans= b+a-1;
		else
		{	
			ans= a;
			a++;
		}
		b--;		
	}		
	else
	{
		if(a%2!=0)
		{
			ans=ans^a^(a+b-1);
			b-= 2;	
		}
	}	
	if(b%4==0)
		return ans;	
	else
		return ans^1;	
}
int main()
{
	int n;	
	while(scanf("%d",&n)!=EOF)
	{
		__int64 ans=0;
		for(int i=1; i<= n; i++)
			scanf("%I64d %I64d",&x[i],&m[i]);
		for(int i=1; i<= n; i++)
		{
				ans^=f(x[i],m[i]);
		}
		cout<<ans<<endl;
		if(ans)
			printf("tolik\n");
		else
			printf("bolik\n");				
	}
return 0;
}
