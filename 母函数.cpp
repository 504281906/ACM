#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int N;
    int c1[125],c2[125];
    while(cin>>N)
    {
        int i,j,k;
        for(i=0;i<=N;i++)//��ʼ����һ�����ʽ��ϵ��
        {
            c1[i]=1;
            c2[i]=0;
        }
        for(i=2;i<=N;i++)
        {//�ӵڶ������ʽ��ʼ����Ϊ�������Ƹ���������n�����ʽ
            for(j=0;j<=N;j++)
            {//���۳˵ı��ʽ���һ�����ʽ��һ�������һ��
            	if (c1[j]) //��������Լ��ӵ� 
                for(k=0;k+j<=N;k+=i)
                {//kΪ��j��������ָ������i�����ʽÿ���ۼ�i
                    c2[j+k]+=c1[j];
                }
            }
            for(j=0;j<=N;j++)
            {//������������һ�����ʽ�����һ��
                c1[j]=c2[j];
                c2[j]=0;
            }
        }
        printf("%d\n",c1[N]);
    }
    return 0;
}
