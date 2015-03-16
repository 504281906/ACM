#include <stdio.h>
int partions(int l[],int low,int high)
{
int prvotkey=l[low];
l[0]=l[low];
while (low<high)
{
     while (low<high&&l[high]>=prvotkey)
     --high;
     l[low]=l[high];
     while (low<high&&l[low]<=prvotkey) 
     ++low;
     l[high]=l[low];
}
l[low]=l[0];
return low;
}
void qsort(int l[],int low,int high)
{
int prvotloc;
if(low<high)
{
     prvotloc=partions(l,low,high);    //����һ������Ľ����Ϊ����
     qsort(l,low,prvotloc-1); //�ݹ�������� ��low ��prvotloc-1
     qsort(l,prvotloc+1,high); //�ݹ�������� �� prvotloc+1�� high
}
}
void quicksort(int l[],int n)
{
qsort(l,1,n); //��һ����Ϊ���� ���ӵ�һ���ŵ���n��
}
int main()
{
int a[11]={0,2,32,43,23,45,36,57,14,27,39};
for (int b=1;b<11;b++)
printf("%3d",a[b]);
printf("\n");
quicksort(a,11);
for(int c=1;c<11;c++)
printf("%3d",a[c]);
}
