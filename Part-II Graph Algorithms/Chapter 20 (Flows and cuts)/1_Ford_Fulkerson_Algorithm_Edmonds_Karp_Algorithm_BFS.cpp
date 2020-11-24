#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; // namespace created as std

class FordFulkersonGraph
{
	public:
		struct node
		{
			int flow =0, capacity = 0;
			node(){}
			node(int f, int c){flow = f, capacity = c;}
		};
		vector<vector<pair<int, node*>>> graph;
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
			graph.resize(g.size());
			for(int  root= 0; root < (signed) g.size(); root ++)
			{
				for(auto child: g[root])
				{
					graph[root].push_back({child.first, new node(0, child.second)});
				}
			}
		}
		
		void runScript()
		{
			if(true == true)
			{
				cout<<"There is a source path from source to sink: ";
				
			}
			else
			{
				cout<<"There is not path from source to sink.";
			}
			
			print_everything();
		}
		
		bool bfs(int currSource, int currSink, vector<int> parent)
		{
			vector<bool> visited(this->vertices, false); // none of them visited yet
			queue<int> q;
			q.push_back(currSource);
			visited[currSource] = true;
			parent[currSource] = -1;
			
			while(!q.empty())
			{
				int currNode = q.front();
				q.pop();
				
				for(int child: graph[currNode])
				{
					if(visited[child] == false)
					{
						q.push_back(child);
						parent[child] = currNode;
						visited[child] = true;
					}
				}
			}
			
			return (visited[currSink] == true);
		}
		
		int fordFulkersonAlgorithm()
		{
			
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
