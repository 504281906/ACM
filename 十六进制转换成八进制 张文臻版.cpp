#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<limits.h>
using namespace std;

char ch[400000];
int a[400000];

int pd(char h)
{
	if(h>='0' && h<= '9')
		return h- '0';
	else 
		return h- 'A' + 10;	
}

int main()
{
	int T; scanf("%d",&T);
	while(T--)
	{
		memset(a,0,sizeof(a));
		scanf("%s",&ch);
		int l= strlen(ch);
		a[0]= pd(ch[l-1]);
		if(a[0]>= 8)
		{
			a[1]+= a[0] / 8;
			a[0]%= 8;
		}
		for(int i= l-2,j= 1; i>= 0; i--,j++)
		{
			int t;
			t=  pd(ch[i]);
			if(j%3==0)
				a[(j/3)*4] +=  t;
			else if(j%3==1)
				a[(j/3)*4 + 1] += t* 2;
			else
				a[(j/3)*4 + 2] += t *4;	
			/*if(a[j] > 8)
			{
				a[j+1]+= a[j] / 8;
				a[j] %= 8; 
			}
			*/
		}
		int max= 4*(l+3)/3;
		for(int i= 0; i<= max; i++)
		{
			a[i+1] += a[i]/8;
			a[i]%= 8;
		}
	/*	while(a[max])
		{
			a[max+1]= a[max] /8;
			a[max]%= 8;
			max++;
		}
		*/
		int flag= 0;
		for(int i= max; i>= 0; i--)
		{
			if(flag)
				printf("%d",a[i]);
			else
			{
				if(a[i])
				{
					printf("%d",a[i]);
					flag= 1;
				}	
			}
		}
		printf("\n");
	}
		return 0;
}
