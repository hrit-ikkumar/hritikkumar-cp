// @hritikkumar

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; // namespace created as std

void dfsUtil(unordered_map<int,vector<int>> &graph, 
					int node, stack<int> &stk, 
					unordered_map<int, bool> &visited)
{
	visited[node] = true;
	for(auto u: graph[node])
	{
		if(!visited[u])
		{
			dfsUtil(graph, u, stk, visited);
		}
	}
	stk.push(node);
}

void dfsUtilSC(unordered_map<int,vector<int>> &reversedGraph, 
						int node, vector<int> &stronglyConnected, 
						unordered_map<int, bool> &visited)
{
	visited[node] = true;
	stronglyConnected.push_back(node);
	for(auto u: reversedGraph[node])
	{
		if(!visited[u])
		{
			dfsUtilSC(reversedGraph, u, stronglyConnected, visited);
		}
	}
}

map<int, vector<int>> kosarajuAlgorithm(unordered_map<int, vector<int>> &graph, 
																  unordered_map<int, vector<int>> &reversedGraph)
{
	vector<vector<int>> ans;
	vector<bool> visited(graph.size(), false);
	stack<int> stk;
	
	// fist time dfs
	for(int node = 0; node < (signed) graph.size(); node++)
	{
		if(!visited[node])
		{
			dfsUtil(graph, node, stk, visited);
		}
	}
	
	// second time dfs
	visited.assign(visited.size(), false);
	while(!stk.empty())
	{
		int currNode = stk.top(); stk.pop();
		if(!visited[currNode])
		{
			vector<int> stronglyConnected;
			dfsUtilSC(reversedGraph, currNode, stronglyConnected, visited);
			ans.push_back(stronglyConnected);
		}
	}
	return ans;
}

int main(void)
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); // fastio
	#ifdef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	 
	int v, e, m; // m is no. of clauses 
	cin>>v>>m; // v -> total no. of nodes
	e = 2 * v; // edges = twice of vertices 
	vector<int> start, end; // start -> end clause, -ve sign means that that is complement of that node
	
	unordered_map<int, vector<int>> graph, reversedGraph;
	for(int i=0;i<m;i++)
	{
		cin>>start[i]>>end[i];
	}
	
	// Convert the given sequence into map using map
	for(int i=0;i<m;i++)
	{
		graph[start[i]].push_back(end[i]); // start[i] -> end[i]
		reversedGraph[end[i]].push_back(start[i]); // end[i] -> start (reverse)
	}
	 map<int, vector<int>> ans = kosarajuAlgorithm(graph, reversedGraph); // result of that algorithm
	 
	 
}

