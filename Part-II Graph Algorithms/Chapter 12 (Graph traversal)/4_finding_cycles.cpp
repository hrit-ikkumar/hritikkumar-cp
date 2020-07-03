// @hritikkumar

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; // namespace created as std

bool dfs(vector<vector<int>> &, vector<bool> &, int);

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
	/*vector<bool> visited(vertices, false);
	
	if(dfs(graph, visited, 0))
		cout<<"CYCLE"<<endl;
	else
		cout<<"NOT CYCLE"<<endl;*/
	if(edges>=vertices)
		cout<<"CYCLE"<<endl;
	else
		cout<<"NOT CYCLE"<<endl;
	return 0; // return type is int 
}

bool dfs(vector<vector<int>> &graph,vector<bool> &visited,  int current)
{
	visited[current] = true;
	for(auto u: graph[current])
	{
		if(visited[u])
			return true;
		dfs(graph, visited, u);
	}
	return false;
}
