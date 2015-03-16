#include <cstdio>
#include <cstring>
#define maxn 10000

char ch[maxn+5];
int L0[maxn+5], L1[maxn+5];

int main()
{
	while(scanf("%s",ch+1)!=EOF)
	{
		int L= strlen(ch+1);
		L0[0]= L1[0]= 0;
		for(int i= 1; i<= L; i++)
		{
			L0[i]= L0[i-1];
			L1[i]= L1[i-1];
			if(ch[i]=='(')
				L0[i]++;
			else
				L1[i]++;	
		//	printf("%d %d\n",L1[i]);
		}
		int flag= 0;
		for(int i= L-1; i>= 2; i--)
			if(ch[i]=='(' && L0[i]-1>= L1[i]+1)
			{
			//	printf("%d %d %d\n",i, L0[i]-1, L1[i]+1);
				flag= i;
				break;
			}
	//	printf("%d\n",flag);	
		if(!flag)
			printf("No solution\n");
		else
		{
			ch[flag]= ')';
			ch[L]='(';
			for(int i= 1; i<= flag; i++)
				printf("%c",ch[i]);
			for(int  i= L; i> flag; i--)	
				printf("%c",ch[i]);	
			printf("\n");	
		}		
	}
return 0;
}
