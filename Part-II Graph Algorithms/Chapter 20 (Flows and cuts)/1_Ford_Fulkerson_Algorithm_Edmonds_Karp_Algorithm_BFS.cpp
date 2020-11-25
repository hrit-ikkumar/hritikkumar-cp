#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; // namespace created as std

class FordFulkersonGraph
{
	public:
		vector<vector<int>> graph, rGraph;
		int source, sink;
		int vertices, edges;
	
	public:
		FordFulkersonGraph() {}
		FordFulkersonGraph(int v, int edg, int s, int e, vector<vector<pair<int,int>>> g)
		{
			this->source = s;
			this->sink = e;
			this->vertices = v;
			this->edges = edg;
			graph.resize(vertices, vector<int>(vertices, 0));
			rGraph.resize(vertices, vector<int>(vertices, 0));
			for(int  root= 0; root < (signed) g.size(); root ++)
			{
				for(auto child: g[root])
				{
					graph[root][child.first] = child.second;
					rGraph[root][child.first] = child.second; // residual Graph
				}
			}
		}
		
		void runScript()
		{
			cout<<"MAX FLOW: "<<fordFulkersonAlgorithm()<<endl;
			
			print_everything();
		}
		
		bool bfs(int currSource, int currSink, vector<int> &parent)
		{
			vector<bool> visited(this->vertices, false); // none of them visited yet
			queue<int> q;
			q.push(currSource);
			visited[currSource] = true;
			parent[currSource] = -1;
			
			while(!q.empty())
			{
				int currNode = q.front();
				q.pop();
				
				for(int v = 0; v < this->vertices; v++)
				{
					if(visited[v] == false && rGraph[currNode][v] > 0)
					{
						q.push(v);
						parent[v] = currNode;
						visited[v] = true;
					}
				}
			}
			
			return (visited[currSink] == true);
		}
		
		int fordFulkersonAlgorithm()
		{
			vector<int> parent(this->vertices,0);
			int max_flow = 0;
			int u,v;
			while(bfs(source, sink, parent))
			{
				int path_flow = INT_MAX;
				for(v = sink; v != source; v=parent[v])
				{
					u = parent[v];
					path_flow = min(path_flow, rGraph[u][v]);
				}
				
				for(v = sink; v!= source; v= parent[v])
				{
					u = parent[v];
					rGraph[u][v] -= path_flow;
					rGraph[v][u] += path_flow;
				}
				max_flow += path_flow;
			}
			return max_flow;
		}
		
		void print_everything()
		{
			// hritikkumar
			
		}
};

int main(void)
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); // fastio
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int V, E,S,Ed; // vertices, edges, source, end/sink
	cin>>V>>E>>S>>Ed;
	vector<vector<pair<int,int>>> GRAPH(V);
	for(int i=0;i<E;i++)
	{
		int start, end, weight;
		cin>>start>>end>>weight;
		GRAPH[start].push_back({end, weight});
	}
	FordFulkersonGraph* fordFulkersonGraph = new FordFulkersonGraph(V, E, S, Ed, GRAPH); // object
	fordFulkersonGraph -> runScript(); // scripted things
	
	
	return 0; // return type is int
}
