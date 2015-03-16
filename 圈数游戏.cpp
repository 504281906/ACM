#include<iostream>
#include<vector>
using namespace std;

//SeqLis类
class SeqList
{
	char name[10];
        public:
		void DispName(){cout<<name;}
		void SetName(char b[]){strcpy(name,b);}
		void Joseph(vector<SeqList>&);
};


//Joseph函数（类外函数用：： ）
void SeqList::Joseph(vector<SeqList>&c)
{\
	int m,star,i,j,k,s1;
	cout <<"请输入间隔数m：";
	cin>>m;
	while(m>20)
	{
		cout<<"间隔太大请重新输入：";
		cin>>m;
	}
	cout<<"从第几个人的位置开始报数（不能大于"<<c.size()<<"）:";
	cin>>star;
	while(star>c.size())
	{
		cout<<"开始位置大于人数，重新输入：";
		cin>>star;

	}
	cout<<"准备输入名字"<<endl;
	getchar();//消除回车干扰

        //输入参加游戏人的名字
	char s[10];
	for(i=0;i<c.size();i++)
	{
		cout<<"第"<<i+1<<"个人的名字：";
		gets(s);
		c[i].SetName(s);
	}
	i=star-1;//计数时从开始报数处减一
	vector<SeqList>::iterator p;//声名向量的正向泛型指针  语法为：vactor<type>::iterator
	p=c.begin();//p是向量的开始
	int length=c.size();

	for(k=1;k<=length;k++)
	{
                s1=c.size();
		j=0;//开始报数
		while(j<m)
		{
			i++;
                        //报数到最后时返回报第一个
			if(i==s1)
			{
				i=0;
			}
			j++;
		}
		if(k==length) break;//全部出圈后停止循环
		c[i].DispName();
		cout<<"  下一个";
		c.erase(p+i);//调整索引
	
		cout<<endl;
			
		--i;
	}
	cout<<endl;
	cout<<"                      失败者：";
	c[i].DispName();//输出最后一个出圈的人的名字
	
	cout<<endl;
		cout<<endl;
		cout<<endl;
}
void chengfa()
{int q;
if(q==1)
	{
		cout<<"放声唱歌"<<endl;
	}
			if(q==2)
			{
              cout<<"跳一支舞"<<endl;
			}
			if(q==3)
			{
				cout<<"蛙跳100下"<<endl;
			}
			if(q==4)
			{
                cout<<"俯卧撑20个"<<endl;
			}
			if(q==5)
			{
				cout<<"真心话"<<endl;
			}
			if(q==6)
			{
                cout<<"大冒险"<<endl;
			}
			if(q==7)
			{
				cout<<"Good LUck  没有惩罚"<<endl;
			}
			if(q==8)
			{
				cout<<"和某人拥抱"<<endl;
			}
			if(q==9)
			{
				cout<<"和某人Kiss"<<endl;
			}
}

void main()
{
	int length=0;//初始化
	int f;
	int q;
    
	cout<<"                            出圈游戏 "<<endl;

	cout<<endl;
begin:cout<<"1 游戏规则"<<endl;
	cout<<"2 进入游戏"<<endl;
	cout<<"3 退出游戏"<<endl;
//	cout<<"4 游戏惩罚"<<endl;
	cout<<endl;
	cout<<"请输入1或2或3，并在输入2游戏过后输入4进行游戏惩罚"<<endl;
	cin>>f;
	if (f==1) 
	{cout<<"游戏规则如下:"<<endl;
	cout<<"游戏规则是：设有n个人围坐一圈并按顺时针方向从1到n编号，从第s个人开始进行1到m的报数"<<endl;
	cout<<"	报数到第m的人出圈，剩余的人有形成一个圈，再从他的下一个人重新开1到m的报数，"<<endl;
	cout<<"	如此进行下去直到所有人都出圈为止。要求按出圈顺序输出n个人的名字。失败者有惩罚"<<endl;
     cout<<endl;
	 goto begin;
	}
	if(f==2)
	{	cout<<"请输入人数：";
    

	cin>>length;
	vector<SeqList>c(length);
	SeqList game;//用SeqList类创建game对象
	game.Joseph(c);//用game对象调用Joseph(c)函数

  //	cout<<"请输入你喜欢的数字  1-9"<<endl;
	//	chengfa();


		goto begin;
	}
	if(f==3)
	{
		return;
     
	}
	if(f==4)
	{
		cout<<"请输入你喜欢的数字  1-9"<<endl;
		cin>>q;
		chengfa();
		return; 
		goto begin;
	}
	
	//cout<<"请输入人数：";
    
}
//	cin>>length;
//	vector<SeqList>c(length);
//	SeqList game;//用SeqList类创建game对象
//	game.Joseph(c);//用game对象调用Joseph(c)函数
//}
