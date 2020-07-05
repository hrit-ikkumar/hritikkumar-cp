// @hritikkumar

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; 

void dfs(int, int, vector<int> &, vector<vector<int>> &);

int main(void)
{
	std::ios::sync_with_stdio(false); // fastio
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int vertices, edges; cin>>vertices>>edges;
	vector<vector<int>> graph(vertices, vector<int>());
	for(int i=0;i<edges;i++)
	{
		int start, end;
		cin>>start>>end;
		graph[start].push_back(end);
	}
	vector<int> ans(vertices, 0);
	dfs(0,-1, ans, graph);
	for(unsigned int i = 0;i<ans.size();i++)
	{
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0; // return type is int
}

void dfs(int start, int end, vector<int> &ans, vector<vector<int>> & graph)
{
	ans[start] = 1;
	for(auto u: graph[start])
	{
		if(u==end)	continue;
		dfs(u,start, ans, graph);
		ans[start] += ans[u];
	}
}
