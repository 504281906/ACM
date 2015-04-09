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

//Dijkstra算法用到优先队列的结点
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
	long m;//点数和边数
	vector<Edge> edges;//边列表
	vector<int> G[MAX];//每个结点出发的边编号（从0 开始编号）
	bool done[MAX];//是否已永久标号
	int d[MAX]; //s到各个点的距离
	int p[MAX];//最短路中的上一条边

	void init(int n)
	{
		this->n = n;
		for(int i = 0 ; i < n ;i++)
			G[i].clear();//清空邻接表
		edges.clear();//清空边表
	}

	void AddEdge(int from,int to,int dist)
	{
		//如果是无向图，每条边需调用两次AddEdge
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
		//求s到所有点的距离
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
