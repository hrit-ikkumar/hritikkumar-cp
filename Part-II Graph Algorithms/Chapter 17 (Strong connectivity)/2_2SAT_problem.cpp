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
		if( visited.count(u) == 0 && node != 0)
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
		if(visited.count(u) == 0 && node != 0)
		{
			dfsUtilSC(reversedGraph, u, stronglyConnected, visited);
		}
	}
}

vector<vector<int>> kosarajuAlgorithm(unordered_map<int, vector<int>> &graph, 
																  unordered_map<int, vector<int>> &reversedGraph,
																  int v)
{
	vector<vector<int>> ans;
	unordered_map<int, bool> visited;
	stack<int> stk;
	
	// fist time dfs
	for(int node = -v; node <= v; node++)
	{
		if( visited.count(node) == 0 && node != 0)
		{
			dfsUtil(graph, node, stk, visited);
		}
	}
	
	// second time dfs
	visited.clear(); 
	while(!stk.empty())
	{
		int currNode = stk.top(); stk.pop();
		if(visited.count(currNode) == 0 && currNode != 0)
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
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	 
	int v, e, m; // m is no. of clauses 
	cin>>v>>m; // v -> total no. of nodes
	e = 2 * v; // edges = twice of vertices 
	vector<int> start(m), end(m); // start -> end clause, -ve sign means that that is complement of that node
	
	unordered_map<int, vector<int>> graph, reversedGraph;
	for(int i=0;i<m;i++)
	{
		cin>>start[i]>>end[i];
	}
	
	// Convert the given sequence into map using map
	for(int i=0;i<m;i++)
	{
		graph[-start[i]].push_back(end[i]); // start[i] -> end[i]
		graph[-end[i]].push_back(start[i]);
		reversedGraph[end[i]].push_back(-start[i]); // end[i] -> start (reverse)
		reversedGraph[start[i]].push_back(-end[i]);
	}
	 vector<vector<int>> ans = kosarajuAlgorithm(graph, reversedGraph, v); // result of that algorithm
	 unordered_map<int, int> SCC;
	 for(int i=0; i<(signed)ans.size(); i++)
	 {
		 for(int j = 0;j< (signed)ans[i].size() ;j++)
		 {
			 SCC[ans[i][j]] = i;
		 }
	 }
	 for(int node = 1;  node <= v; node++)
	 {
		 if(SCC[node] == SCC[-node])
		{
			cout<<"NOT Satisfiable"<<endl;
			return 0;
		}
	 }
	 cout<<"Satisfiable"<<endl;
	 return 0; // return type is int
}

