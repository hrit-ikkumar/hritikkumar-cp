// @hritikkumar

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; // namespace created as std

void dfs(vector<vector<int>> &, vector<bool> &,vector<int> &, int);

int main(void)
{
	std::ios::sync_with_stdio(false); // fastio
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r",stdin);
	freopen("output.txt", "w", stdout); 
	#endif
	
	int vertices, edges;
	cin>>vertices>>edges;
	vector<vector<int>> graph(vertices);
	while(edges--)
	{
		int start, end;
		cin>>start>>end;
		graph[start].push_back(end);
		graph[end].push_back(start);
	}
	vector<bool> visited(vertices, false);
	vector<int> ans;
	
	dfs(graph, visited, ans, 0);
	for(int i=0;i<signed(ans.size());i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	return 0; // return type is int 
}

void dfs(vector<vector<int>> &graph,vector<bool> &visited,vector<int> &ans,  int current)
{
	if(visited[current]) return;
	
	visited[current] = true;
	ans.push_back(current);
	for(auto u: graph[current])
		dfs(graph, visited, ans, u);
}
