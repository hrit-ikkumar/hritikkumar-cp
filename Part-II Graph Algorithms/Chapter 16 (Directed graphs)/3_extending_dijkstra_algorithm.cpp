// @hritikkumar

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; // namespace created as std

void topoSortDFS(vector<vector<pair<int,int>>> &, vector<bool> &,int, vector<int> &);

vector<int> topologicalSort(vector<vector<pair<int, int>>> &);

int extendedDijkstraAlgorithmDP(vector<vector<pair<int, int>>> &, vector<int> &);

int main(void)
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); // fastio
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt","w", stdout);
	#endif
	int vertices, edges;
	cin>>vertices>>edges;
	vector<vector<pair<int, int>>> graph(vertices, vector<pair<int,int>>(0));
	for(int i=0;i<edges;i++)
	{
		int start, end, weight;
		cin>>start>>end>>weight;
		graph[start].push_back({end, weight});
	}
	vector<int> topo = topologicalSort(graph);
	int ans = extendedDijkstraAlgorithmDP(graph, topo);
	cout<<ans<<endl;
	return 0; // return type is int
}

void topoSortDFS(vector<vector<pair<int,int>>> &graph, vector<bool> &visited,int root, vector<int> &ans)
{
	visited[root] = true;
	for(auto u: graph[root])
	{
		if(!visited[u.first])
		{
			topoSortDFS(graph, visited, u.first, ans);
		}
	}
	ans.push_back(root);
}

vector<int> topologicalSort(vector<vector<pair<int,int>>> & graph)
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

int extendedDijkstraAlgorithmDP(vector<vector<pair<int,int>>> &graph, vector<int> &topoSort)
{
	vector<int> dp_table(graph.size(),INT_MAX);
	dp_table[topoSort[0]] = 0;
	for(int i=0;i<(signed)topoSort.size();++i)
	{
		for(pair<int, int> u: graph[topoSort[i]])
		{
				dp_table[u.first] = min(dp_table[u.first], dp_table[topoSort[i]] + u.second);
		}
	}
	return dp_table[topoSort.back()];
}
