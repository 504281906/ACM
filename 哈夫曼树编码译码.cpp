#include<iostream>   
#include<fstream> //文件操作函数头文件   
#include<iomanip>   
#define Maxvalue 100000   
#define Maxleafsize 40   
#define Maxnode 2*Maxleafsize-1   
#define Maxbit 20   
//二叉树结构定义   
using namespace std; 
typedef struct Node{   
    int weight,lchild,rchild,parent;   
    char data;   
}HffNode;   
typedef struct{   
    int bit[Maxbit];   
    int start;   
}HffCode;   
//建立哈夫曼树的函数定义   
void Create_Haff(HffNode H[],int n)   
{   int i,j,m1,m2,x1,x2;   
    for(i=0;i<2*n-1;i++) //初始化各个结点   
    {   H[i].weight=0;   
        H[i].parent=-1;   
        H[i].lchild=-1;   
        H[i].rchild=-1;   
        H[i].data='#';   
    }   
    cout<<"请输入字符"<<endl;   
    for(i=0;i<n;i++)   
        cin>>H[i].data;//输入叶子结点的权值   
    cout<<"请输入各叶子结点的权值"<<endl;   
    for(i=0;i<n;i++)                    
    cin>>H[i].weight;//通过循环建立哈夫曼树   
    for(i=0;i<n-1;i++)              
    {   m1=m2=Maxvalue;   
        x1=x2=0;   
        for(j=0;j<n+i;j++)//选取最小和次小两个权值   
        {   if(H[j].parent==-1&&H[j].weight<m1)   
            {   m2=m1;   
                x2=x1;   
                m1=H[j].weight;   
                x1=j;   
            }   
            else if(H[j].parent==-1&&H[j].weight<m2)   
            {   m2=H[j].weight;   
                x2=j;   
            }   
        }   
        H[x1].parent=n+i;   
        H[x2].parent=n+i;   
        H[n+i].weight=H[x1].weight+H[x2].weight;   
        H[n+i].lchild=x1;   
        H[n+i].rchild=x2;   
    }   
}   
void Hffcode(HffNode Hnode[],int n) //哈夫曼编码函数      
{   HffCode Hcode[Maxleafsize],cd;   
    int i,j,c,p,k=0,q=0,u=0,t=0;   
    char ch[50],m;     
    for(i=0;i<n;i++)//通过循环实现编码               
    {   cd.start=n-1;   
        c=i;   
        p=Hnode[c].parent;   
        while(p!=-1)   
        {   if(Hnode[p].lchild==c)   
                cd.bit[cd.start]=0;   
            else   
                cd.bit[cd.start]=1;   
                cd.start--;   
                c=p;   
                p=Hnode[c].parent;   
        }   
        for(j=cd.start+1;j<n;j++)   
            Hcode[i].bit[j]=cd.bit[j];   
        Hcode[i].start=cd.start;   
    }   
    for(i=0;i<n;i++)//输出编码                  
    {   cout<<Hnode[i].data<<"的编码为:"<<endl;   
        for(j=Hcode[i].start+1;j<n;j++)   
            cout<<Hcode[i].bit[j];   
        cout<<endl;   
    }      
    fstream ftxt;//文本操作   
    ftxt.open("codefile.txt",ios::out);//信息写入文件；       
    ftxt<<setw(8)<<"Weight"<<setw(8)<<"Lchild"<<setw(8)<<"Rchild"   
        <<setw(8)<<"Parent"<<setw(8)<<"字符值"<<setw(14)<<"编码"<<endl;   
    for(i=0;i<2*n-1;i++)   
    {   ftxt<<setw(8)<<Hnode[i].weight<<setw(8)<<Hnode[i].lchild<<setw(8)   
        <<Hnode[i].rchild<<setw(8)<<Hnode[i].parent<<setw(8)<<Hnode[i].data<<setw(11);   
        for(j=Hcode[k].start+1;j<n&&k<n;j++)//文件操作在屏幕输出编码   
            ftxt<<Hcode[k].bit[j];   
        k++;   
        ftxt<<endl;   
    }   
    cout<<"请输入要编码的字符串以#结束"<<endl;   
    cin>>m;   
    while(m!='#')   
    {ch[t]=m;   
      t++;   
      cin>>m;   
    }   
     ch[t]='#';    
   ftxt<<"要编码的字符串为:";   
    for(i=0;ch[i]!='#';i++)   
        ftxt<<ch[i];   
        ftxt<<endl;   
        ftxt<<"此串编码为:";   
        while(q<n&&ch[u]!='#')//实现编码   
        {   while(Hnode[q].data!=ch[u])   
                q++;   
            for(j=Hcode[q].start+1;j<n;j++)   
            {   cout<<Hcode[q].bit[j];   
              ftxt<<Hcode[q].bit[j];}   
            q=0;   
            u++;   
        }   
        cout<<endl;   
        ftxt<<endl;   
        ftxt.close();   
       
}   
void Hfftran(HffNode H[],int node)  //译码函数   
{   int i=node-1,j=0;char b;   
    cout<<"请输入二进制码按#结束:"<<endl;   
    cin>>b;   
    while(((b=='0')||(b=='1'))&&b!='#')   
    {   if(b=='0')i=H[i].lchild;   
        else i=H[i].rchild;   
        if(H[i].lchild==-1&&H[i].rchild==-1)   
        {   cout<<H[i].data;   
            i=node-1;   
        }   
        cin>>b;   
    }   
    cout<<endl;   
}   
int main()   
{      
        char c;int n,i,k=0;HffNode Hnode[Maxnode];   
        cout<<"************欢迎使用哈夫曼编码系统************"<<endl;   
        cout<<"首先建立哈夫曼树"<<endl;   
        cout<<"请输入字符集大小n:"<<endl;   
        cin>>n;   
        Create_Haff(Hnode,n);   
        cout<<"哈夫曼树已建好"<<endl;   
        cout<<endl;   
        cout<<"1--进行哈夫曼树编码"<<endl;   
        cout<<"2--进行哈夫曼树译码"<<endl;   
        cout<<"3--打印哈夫曼树"<<endl;   
        cout<<"0--退出程序"<<endl;    
A:      cout<<"请选择操作"<<endl ;   
        cin>>c;          
        if(c=='1')   
        { Hffcode(Hnode,n);goto A;}   
        else if(c=='2')   
        {   Hfftran(Hnode,2*n-1);goto A;}   
        else if(c=='3')   
        {   
			cout<<setw(8)<<"Weight"<<setw(8)<<"Lchild"<<setw(8)<<"Rchild"<<setw(8)<<"Parent"<<setw(8)<<"字符值"<<endl;   
            for(i=0;i<2*n-1;i++)   
            {   cout<<setw(8)<<Hnode[i].weight<<setw(8)<<Hnode[i].lchild<<setw(8)   
                <<Hnode[i].rchild<<setw(8)<<Hnode[i].parent<<setw(8)<<Hnode[i].data<<setw(11)<<endl;   
            }   
            goto A;   
        }   
        else if(c=='0')   
        {   cout<<"谢谢使用"<<endl;
			return 0;}   
        else {cout<<"输入有误,请重试。"<<endl;goto A;}   
       
} 
