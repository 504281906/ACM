#include<iostream>
#include<vector>
using namespace std;

//SeqLis��
class SeqList
{
	char name[10];
        public:
		void DispName(){cout<<name;}
		void SetName(char b[]){strcpy(name,b);}
		void Joseph(vector<SeqList>&);
};


//Joseph���������⺯���ã��� ��
void SeqList::Joseph(vector<SeqList>&c)
{\
	int m,star,i,j,k,s1;
	cout <<"����������m��";
	cin>>m;
	while(m>20)
	{
		cout<<"���̫�����������룺";
		cin>>m;
	}
	cout<<"�ӵڼ����˵�λ�ÿ�ʼ���������ܴ���"<<c.size()<<"��:";
	cin>>star;
	while(star>c.size())
	{
		cout<<"��ʼλ�ô����������������룺";
		cin>>star;

	}
	cout<<"׼����������"<<endl;
	getchar();//�����س�����

        //����μ���Ϸ�˵�����
	char s[10];
	for(i=0;i<c.size();i++)
	{
		cout<<"��"<<i+1<<"���˵����֣�";
		gets(s);
		c[i].SetName(s);
	}
	i=star-1;//����ʱ�ӿ�ʼ��������һ
	vector<SeqList>::iterator p;//����������������ָ��  �﷨Ϊ��vactor<type>::iterator
	p=c.begin();//p�������Ŀ�ʼ
	int length=c.size();

	for(k=1;k<=length;k++)
	{
                s1=c.size();
		j=0;//��ʼ����
		while(j<m)
		{
			i++;
                        //���������ʱ���ر���һ��
			if(i==s1)
			{
				i=0;
			}
			j++;
		}
		if(k==length) break;//ȫ����Ȧ��ֹͣѭ��
		c[i].DispName();
		cout<<"  ��һ��";
		c.erase(p+i);//��������
	
		cout<<endl;
			
		--i;
	}
	cout<<endl;
	cout<<"                      ʧ���ߣ�";
	c[i].DispName();//������һ����Ȧ���˵�����
	
	cout<<endl;
		cout<<endl;
		cout<<endl;
}
void chengfa()
{int q;
if(q==1)
	{
		cout<<"��������"<<endl;
	}
			if(q==2)
			{
              cout<<"��һ֧��"<<endl;
			}
			if(q==3)
			{
				cout<<"����100��"<<endl;
			}
			if(q==4)
			{
                cout<<"���Գ�20��"<<endl;
			}
			if(q==5)
			{
				cout<<"���Ļ�"<<endl;
			}
			if(q==6)
			{
                cout<<"��ð��"<<endl;
			}
			if(q==7)
			{
				cout<<"Good LUck  û�гͷ�"<<endl;
			}
			if(q==8)
			{
				cout<<"��ĳ��ӵ��"<<endl;
			}
			if(q==9)
			{
				cout<<"��ĳ��Kiss"<<endl;
			}
}

void main()
{
	int length=0;//��ʼ��
	int f;
	int q;
    
	cout<<"                            ��Ȧ��Ϸ "<<endl;

	cout<<endl;
begin:cout<<"1 ��Ϸ����"<<endl;
	cout<<"2 ������Ϸ"<<endl;
	cout<<"3 �˳���Ϸ"<<endl;
//	cout<<"4 ��Ϸ�ͷ�"<<endl;
	cout<<endl;
	cout<<"������1��2��3����������2��Ϸ��������4������Ϸ�ͷ�"<<endl;
	cin>>f;
	if (f==1) 
	{cout<<"��Ϸ��������:"<<endl;
	cout<<"��Ϸ�����ǣ�����n����Χ��һȦ����˳ʱ�뷽���1��n��ţ��ӵ�s���˿�ʼ����1��m�ı���"<<endl;
	cout<<"	��������m���˳�Ȧ��ʣ��������γ�һ��Ȧ���ٴ�������һ�������¿�1��m�ı�����"<<endl;
	cout<<"	��˽�����ȥֱ�������˶���ȦΪֹ��Ҫ�󰴳�Ȧ˳�����n���˵����֡�ʧ�����гͷ�"<<endl;
     cout<<endl;
	 goto begin;
	}
	if(f==2)
	{	cout<<"������������";
    

	cin>>length;
	vector<SeqList>c(length);
	SeqList game;//��SeqList�ഴ��game����
	game.Joseph(c);//��game�������Joseph(c)����

  //	cout<<"��������ϲ��������  1-9"<<endl;
	//	chengfa();


		goto begin;
	}
	if(f==3)
	{
		return;
     
	}
	if(f==4)
	{
		cout<<"��������ϲ��������  1-9"<<endl;
		cin>>q;
		chengfa();
		return; 
		goto begin;
	}
	
	//cout<<"������������";
    
}
//	cin>>length;
//	vector<SeqList>c(length);
//	SeqList game;//��SeqList�ഴ��game����
//	game.Joseph(c);//��game�������Joseph(c)����
//}
