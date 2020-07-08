// @hritikkumar

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; // namespace created as std

void dfs(vector<vector<int>> &,vector<int> &,  int );

int main(void)
{
	std::ios::sync_with_stdio(false); // fastio
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int vertices, edges;
	cin>>vertices>>edges;
	vector<vector<int>> graph(vertices,vector<int>());
	for(int i=0;i<edges;i++)
	{
		int start, end;
		cin>>start>>end;
		graph[start].push_back(end);
	}
	vector<int> toLeaf(vertices, 0), maxLength(vertices, 0);
	dfs(graph,toLeaf, 0);
	for(int x: toLeaf)
	cout<<x<<" ";
	cout<<endl;
	return 0; // return type is int
}

void dfs(vector<vector<int>> &graph,vector<int>  &toLeaf, int current)
{
	for(auto u:graph[current])
	{
		dfs(graph,toLeaf, u);
		toLeaf[current] = max(toLeaf[current], toLeaf[u] + 1);
	}
}
