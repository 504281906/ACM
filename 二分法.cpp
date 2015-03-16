#include <cstdio>
int BinSearch(SeqList * R, int n , KeyType K )
{ 
    //�������R[0..n-1]�н��ж��ֲ��ң��ɹ�ʱ���ؽ���λ�ã�ʧ��ʱ����-1
    int low=0,high=n-1,mid; //�õ�ǰ���������ϡ��½�ĳ�ֵ
    if(R[low].key==K)
    {
        return low ;
	}
    if(R[high].key==k)
        return high;
    while(low<=high)
    { 
        //��ǰ��������R[low..high]�ǿ�
        mid=low+((high-low)/2);//ʹ�� (low + high) / 2 ����������������⣨���������ڵ�low + high�Ľ�����ڱ��ʽ����������ܱ�ʾ�����ֵʱ�������������������/2�ǲ��������ȷ����ģ���low+((high-low)/2)�������������
        if(R[mid].key==K)
        {
            return mid; //���ҳɹ�����
        }
        if(R[mid].key>K)
            high=mid-1; //������R[low..mid-1]�в���
        else
            low=mid+1; //������R[mid+1..high]�в���
    }
    if(low>high)
        return -1;//��low>highʱ��ʾ��������Ϊ�գ�����ʧ��
} //BinSeareh

