// @hritikkumar

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; // namespace created as std

bool dfs(vector<vector<int>> &,vector<int> &, int, int);

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
	}
	vector<int> color(vertices, -1);
	bool ans = dfs(graph, color, 0, 1);
	if(ans)
	{
		for(int x: color)
			cout<<x<<" ";
		cout<<endl;
	}
	else
		cout<<"COLORING is not POSSIBLE!"<<endl;
	return 0; // return type is int 
}

bool dfs(vector<vector<int>> &graph, vector<int> &color,  int current, int setColor)
{
	if(color[current] != -1 && color[current] != setColor)
		return false;
	color[current] = setColor;
	for(auto u: graph[current])
	{
		if(color[u]==-1)
		{
			if(!dfs(graph, color, u, 1 - setColor))
				return false;
		}
		if(color[u] == color[current])
			return false;
	}
	return true;
}
