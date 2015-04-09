#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

#define MAX 20005

struct Edge
{
	int from ;
	int to;
	int dist;

};

//Dijkstra�㷨�õ����ȶ��еĽ��
struct HeapNode
{
	int d,u;
	bool operator < (const HeapNode& rhs) const 
	{
		return d > rhs.d;
	}
};

struct Dijkstra
{
	int n;
	long m;//�����ͱ���
	vector<Edge> edges;//���б�
	vector<int> G[MAX];//ÿ���������ı߱�ţ���0 ��ʼ��ţ�
	bool done[MAX];//�Ƿ������ñ��
	int d[MAX]; //s��������ľ���
	int p[MAX];//���·�е���һ����

	void init(int n)
	{
		this->n = n;
		for(int i = 0 ; i < n ;i++)
			G[i].clear();//����ڽӱ�
		edges.clear();//��ձ߱�
	}

	void AddEdge(int from,int to,int dist)
	{
		//���������ͼ��ÿ�������������AddEdge
		Edge e;
		e.from = from ;
		e.to = to;
		e.dist = dist;
		edges.push_back(e);
		int mm = edges.size();
		G[from].push_back(mm-1);
	}

	void dijkstra(int s)
	{
		//��s�����е�ľ���
		priority_queue<HeapNode> Q;
		for(int i=0;i<n;i++)
			d[i]=MAX;
		d[s]=0;
		memset(done,0,sizeof(done));
		HeapNode h0;
		h0.d=0;
		h0.u=s;
		Q.push(h0);
		while(!Q.empty())
		{
			HeapNode x = Q.top();
			Q.pop();

			int u = x.u;
			if(done[u])
				continue;

			done[u] = true;
			for(int i=0;i<G[u].size();i++)
			{
				Edge& e = edges[G[u][i]];
				if(d[e.to] > d[u] + e.dist)
				{
					d[e.to] = d[u] + e.dist;
					p[e.to] = G[u][i];
					HeapNode h;
					h.d = d[e.to];
					h.u = e.to;
					Q.push(h);
				}
			}
		}
	}
};

int main()
{
	Dijkstra D;

	while(cin>>D.n>>D.m)
	{
		D.init(D.n);
		int from , to ,dist;
		for(long i=0;i<D.m;i++)
		{
			cin>>from>>to>>dist;
			D.AddEdge(from-1,to-1,dist);
		}
		D.dijkstra(0);

		for(int i=1;i<D.n;i++)
			cout<<D.d[i]<<endl;
	}

	return 0;
}
