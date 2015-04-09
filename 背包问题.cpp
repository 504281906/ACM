#include <stdio.h>
#define N 7
#define S 15
typedef struct 
{
    int s;/*s表示考查过（就是装入）该物品后，背包所能盛放的物品的重量*/
    int	n;/*n表示待考查的下一个物品在数组w中的下标*/
    int job;/*job表示当前物品的状态*/                          
} KNAPTP;
int w[N+1] = {0,1,4,3,4,5,2,7}; /*w表示待考查 一组物品的重量，当然现实中没有重量为0的物体*/
int knap(int s,int n)  /*求出一组物品的解并在屏幕上打印它们*/                                
{
    KNAPTP stack[100],x;  /*定义一个stack数组（用于保存已查过的物品）及x，其数据类型为typedef*/
    int top, k; /*top是stack栈顶标志；k为是否求得解的标志；rep也是标志变量，意义见下面*/
    x.s = s; x.n = n;  /*对工作节点x的s、n分量分别付初值*/
    x.job = 0;  /*x.job分量为0表示开始背包中没有放入任何物品，赋初值*/
    top = 1; stack[top] = x; /*置top标志为1，将x节点压入stack栈*/
    k = 0; /*k也赋初值，当然这时候没有解*/
    while ( top>0 && k == 0 )  /*考查各个物品i的选择情况*/
    { 
        x = stack[top];  /*从栈顶取出物品，放入工作节点x*/
		/*rep表示是否继续，赋初值1表示继续进行*/                                   
        while ( !k) /*当k等于0且rep为1时继续循环*/
        {
            if(x.s==0)
                k=1;/*x.s为0表示如果背包所能盛放的物品的重量为0（即装满），则已求得一组解*/
            else 
                if (x.s<0||x.n<=0) 
                    break;  /*否则当x.s小于0或x.n小于等于0，则rep为0，表示停止动作*/
                 else 
                 {
                     x.s=x.s-w[x.n--]; 
                     x.job=1;       /*否则将背包的可承重量减去选中的当前物品重量，同时选择下个物品（n--），x.job置为1表示当前物品可以放入*/
                     stack[++top]= x;/*stack的top标志加1，并将工作节点（选中的下个物品）x放入栈顶*/
                 }
        }
        if ( !k )  /*如果k等于0，暗含rep此时为0，就是处理所考查的物品不满足放入背包的条件时的情况*/                  
        {                            
            while (top>=1)          
            { 
                x = stack[top--];     /*将栈顶物品放入工作节点x*/
                if(x.job==1)  /*如果该物品的job状态等于1，这时也一定为1*/
                {
                    x.s+=w[x.n+1]; /*将x工作节点s分量即当前背包的可承载重量恢复，即将（上一个）不满足条件的物品的重量加回去*/
                    x.job=2; /*置x的job分量为2，表示该物品不能放入背包，在以后的选择中将不考虑该物品*/
                    stack[++top] = x;/*将x压入栈顶*/
                    break;
                }
            } 
        } 
    } 
    if (k)
    {          /*输出一组解*/ 
        while (top>=1)
        {
            x =stack [top--];
            if ( x.job==1 )
                printf ("%d ",w[x.n+1] ); /*一定要下标加1*/
        } 
    } 
    return k;
}
void main()
{ 
    if (!knap(S,N)) 
        printf("\n无解"); 
          
}
