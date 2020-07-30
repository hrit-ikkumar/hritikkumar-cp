// @hritikkumar

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; // namespace created as std

void topoSortDFS(vector<vector<int>> &, vector<bool> &,int, vector<int> &);

vector<int> topologicalSort(vector<vector<int>> &);

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
	for(int i=0;i<edges;i++)
	{
		int start, end;
		cin>>start>>end;
		graph[start].push_back(end);
	}
	vector<int> topo = topologicalSort(graph);
	for(int x: topo)
	cout<<x<<" ";
	cout<<endl;	
	return 0; // return type is int
}

void topoSortDFS(vector<vector<int>> &graph, vector<bool> &visited,int root, vector<int> &ans)
{
	visited[root] = true;
	for(int u: graph[root])
	{
		if(!visited[u])
		{
			topoSortDFS(graph, visited, u, ans);
		}
	}
	ans.push_back(root);
}

vector<int> topologicalSort(vector<vector<int>> & graph)
{
	vector<int> ans(0);
	vector<bool> visited(graph.size(), false);
	for(int i=0;i<(signed)graph.size();i++)
	{
		if(!visited[i])
		{
			topoSortDFS(graph, visited,i, ans);
		}
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
