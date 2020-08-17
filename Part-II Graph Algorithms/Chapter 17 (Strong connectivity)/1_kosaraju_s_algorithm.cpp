// @hritikkumar

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; // namespace created as std

void dfsUtil(vector<vector<int>> &graph, int node, stack<int> &stk, vector<bool> &visited)
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

void dfsUtilSC(vector<vector<int>> &reversedGraph, int node, vector<int> &stronglyConnected, vector<bool> &visited)
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

vector<vector<int>> kosarajuAlgorithm(vector<vector<int>> &graph, vector<vector<int>> &reversedGraph)
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
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	int vertices, edges;
	cin>>vertices>>edges;
	vector<vector<int>> graph(vertices, vector<int>(0)), reversedGraph(vertices, vector<int>(0));
	for(int i=0;i<edges;i++)
	{
		int start, end;
		cin>>start>>end;
		graph[start].push_back(end);
		reversedGraph[end].push_back(start);
	}
	vector<vector<int>> ans = kosarajuAlgorithm(graph, reversedGraph);
	for(int i=0;i<(signed)ans.size(); i++)
	{
		cout<<i<<": {";
		for(int j=0;j<(signed)ans[i].size(); ++j)
		{
			cout<<ans[i][j]<<" ";
		}
		cout<<"}"<<endl;
	}
	return 0; // return type is int 
}
