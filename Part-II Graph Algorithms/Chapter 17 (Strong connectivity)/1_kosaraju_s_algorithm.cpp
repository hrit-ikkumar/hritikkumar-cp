// @hritikkumar

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; // namespace created as std


vector<vector<int>> kosarajuAlgorithm(vector<vector<int>> &graph, vector<vector<int>> &reversedGraph)
{
	vector<vector<int>> ans(0);
	vector<bool> visited(graph.size(), false);
	stack<int> stk;
	
	
	
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
		reversedGraph[end].push_back(end);
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
