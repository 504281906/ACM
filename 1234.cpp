#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
char a[10];
int sg[1000001];
void init()
{
    int ss;
    int i,k;
    int len;
    char j;
    char wei;
    char t[10];
    int temp;
    sg[0]=1;
    for(k=1;k<1000000;k++)  //��ɨ
    {
         ss=1;
        itoa(k,a,10);
        len=strlen(a);
        for(i=0;i<len && ss;i++)
        {
            wei=a[i];
            j='0';
            if(!i) j++;  //ǰ��0�Ļ�Ϊ��ʤ״̬���ɺ��� 
            if(wei=='0') //0ʱ���ģ�� 
            {
                for(j=0;j<i;j++) t[j]=a[j];   
                t[i]='\0';
                temp=atoi(t);
                ss=sg[temp];
            }
            else 
            {
                for(;j<wei && ss;j++)  //����һ��ss=0���Ǳ�ʤ̬ 
                {
                    a[i]=j;
                    temp=atoi(a);
                    ss=sg[temp];
                }
            }
            a[i]=wei;
        }
        sg[k]=!ss;  //״̬ȡ����sg=1Ϊ��ʤ 
    }
}
int main()
{
    int n,i,j,k,t;
    int p;
    int sign;
    init();
    while(scanf("%s",a)!=EOF)
    {
        sign=1;
        if(a[0]!='0')   //��һ��Ϊ0��ֱ��Ӯ�� 
        {
            p=atoi(a);
            sign=sg[p];
        }
        if(sign) puts("Yes");
        else puts("No");
    }
    return 0;
}
