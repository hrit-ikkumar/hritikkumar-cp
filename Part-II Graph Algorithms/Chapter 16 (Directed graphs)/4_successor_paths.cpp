// hritikkumar

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; // namespace created as std 

void dfs(vector<vector<int>> &,int, vector<int> &);

vector<int> succPathFun(vector<vector<int>> &);

int main(void)
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); // fastio
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int vertices, edges;
	cin>>vertices>>edges;
	vector<vector<int>> graph(vertices, vector<int>(0));
	for(int i=0;i<edges;++i)
	{
		int start, end;
		cin>>start>>end;
		graph[start].push_back(end);
	}
	// Successor Graph or Functional Graphs
	/*
	 * Out-Degree = 1
	 * Cotain Multiple Component and in each one of those component, there will be only one cycle.
	 */
	// Successor from Node = 1
	vector<int> successor = succPathFun(graph);
	for(int i=0;i<vertices;i++)
	cout<<i+1<<" ";
	cout<<endl;
	for(int x: successor)
	cout<<x<<" ";
	cout<<endl;
	
	// Successor from all possiblities
	// succ(x, k) from k to x (k -> x)
	
	return 0; // return type is int
}

void dfs(vector<vector<int>> &graph,int root, vector<int> &succ)
{
	if(succ[root] == -1)
	{
		succ[root] = graph[root][0];
	}
}

vector<int> succPathFun(vector<vector<int>> &graph)
{
	vector<int> ans(graph.size(), -1);
	for(int i=0;i<(signed)graph.size();i++)
	{
		dfs(graph,i, ans);
	}
	return ans;
}
