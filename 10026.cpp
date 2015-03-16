#include <stdio.h>
#include <stdlib.h>
#define MAXN 1010
struct Things
{
    int days;
    int fine;
    int num;
};
struct Things task[MAXN];
void BubbleSort(int N)
{
    int i,j;
    int flag=1;
    struct Things ans;
    long long int temp1,temp2;
    for (i=1; i<N && flag; i++)
    {
        flag=0;
        for (j=0; j<N-i; j++)
        {
            temp1=task[j].fine*task[j+1].days;
            temp2=task[j+1].fine*task[j].days;
            if (temp1<temp2)
            {
	     	    ans=task[j];
   	    	    task[j]=task[j+1];
    		    task[j+1]=ans;
      	      flag=1;
            }
        }
    }
    return;
}
int main()
{
    int i;
    int T,N;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&N);
        for (i=0; i<N; i++)
        {
            scanf("%d%d",&task[i].days,&task[i].fine);
            task[i].num=i+1;
        }
        BubbleSort(N);
        printf("%d",task[0].num);
        for (i=1;i<N;i++)
           printf(" %d",task[i].num);
        putchar('\n');
        if (T) putchar('\n');
    }
    return 0;
}

