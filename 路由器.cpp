# include <iostream>
# include <fstream>
# include <string>
# include <sstream>
# include <windows.h>
# include <iomanip>
using namespace std;
int num1;
int num2;
string name1;
string name2;


class Routelists
{
public:
	string net;
	int distance;
	string next_route;
};

class Network
{
public:
	//Network();
	void getin();
	void send();
	void plus(int i);
	void updata();
	void show();
	//int num1;
    //int num2;
	Routelists rts1[20];
    Routelists rts2[20];
	Routelists rts3[20];
private:
};

void Network::getin()
{
	cout<<"请输入路由器的名字和路由表的记录数"<<endl;
	cin>>name1>>num1;
	cout<<"请输入路由器"<<name1<<"的记录"<<endl;
	for(int i=0;i<num1;i++)
	{
		//getchar();
		 cin>>rts1[i].net>>rts1[i].distance>>rts1[i].next_route;
	}
	//for(int j=0;j<num1;j++)
	//	cout<<rts1[j].net<<rts1[j].distance<<rts1[j].next_route;
}

void Network::send()
{
    cout<<"输入发送信息的路由器名字与路由表的记录数"<<endl;
    cin>>name2;
	cin>>num2;
	cout<<"输入发送信息的路由器的路由表"<<endl;
	for(int i=0;i<num2;i++)
	{
		cin>>rts2[i].net>>rts2[i].distance>>rts2[i].next_route;
	}
}

void Network::plus(int i)
{
    rts3[i].distance=rts2[i].distance+1;
	rts3[i].next_route=name2;
	rts3[i].net=rts2[i].net;
	//cout<<rts3[i].net<<"  "<<rts3[i].distance<<"  "<<rts3[i].next_route<<endl;
}

void Network::show()
{
	cout<<"更新后的路由表"<<name1<<"为"<<endl;
	cout<<"目的网络"<<"   "<<"距离"<<"   "<<"下一跳地址"<<endl;
	for(int i=0;i<num1;i++)
	{
		cout<<rts1[i].net<<"        "<<rts1[i].distance<<"       "<<rts1[i].next_route<<endl;
	}
}

void Network::updata()
{
	    getin();
	    send();
		for(int i=0;i<num2;i++)   //距离加一，下一跳路由变为发送路由表的路由器名
			plus(i);
		for(int j=0;j<num2;j++)   //出发送路由表中接收方不存在的目的网络，是为新的项目，向路由表添加
		{
			int count=0;          //定义一个计数器
			for(int k=0;k<num1;k++)
			{	
				if(rts3[j].net!=rts1[k].net)
					count=count+1;		
			}
			if(count==num1)        //路由表的记录数等于计数器，则发送方有新的网络
			{
				rts1[num1].distance=rts3[j].distance;
				rts1[num1].net=rts3[j].net;
				rts1[num1].next_route=rts3[j].next_route;
				num1=num1+1;
			}
		}
        //for(int num=0;num<num1;num++)
		//{cout<<rts3[num].net<<"  "<<rts3[num].distance<<"  "<<rts3[num].next_route<<endl;}
		for(int y=0;y<num2;y++)
		{
			for(int z=0;z<num1;z++)
			{
				if(rts3[y].net==rts1[z].net)  //比较相同的网络
				{
					if(rts3[y].next_route==rts1[z].next_route) //相同的下一跳,距离更新
						rts1[z].distance=rts3[y].distance;
					else
						if(rts3[y].distance<rts1[z].distance)
							rts1[z].distance=rts3[y].distance; //不同的下一跳，距离更短，距离更新
				}
			}
		}
}

int main()
{
    Network nt;
	nt.updata();
	nt.show();
	return 0;
}
