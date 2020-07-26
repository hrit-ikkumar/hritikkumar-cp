// @hritikkumar

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; // namespace created as std

void dfs(vector<vector<int>> &, vector<bool> &,int , int &, int , int & );

void distance_dfs(vector<vector<int>> &, vector<bool> &, vector<int> &, int, int);

int main(void)
{
	std::ios::sync_with_stdio(false); // fastio
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int vertices, edges;
	cin>>vertices>>edges;
	vector<vector<int>> graph(vertices, vector<int>(0));
	for(int i=0;i<edges; i++)
	{
		int start, end;
		cin>>start>>end;
		graph[start].push_back(end);
		graph[end].push_back(start);
	}
	// diameter of tree => dfs from one node(x) to find the farthest node(a) then again do a dfs from node(a) is node(b) so the answer is distance between a and b (b-a) ans 
	vector<bool> visited(vertices, false);
	// first_end  = a, second_end = b
	int x = 0,a = 0,b = 0, maxCount = 0;
	dfs(graph, visited, x, a,0, maxCount);
	visited.assign(visited.size(), false);
	dfs(graph, visited, a,b, 0, maxCount);
	
	vector<int> distance_from_a(vertices, 0), distance_from_b(vertices, 0);
	
	visited.assign(vertices, false);
	distance_dfs(graph,visited, distance_from_a, a, 0);
	
	visited.assign(vertices, false);
	distance_dfs(graph, visited, distance_from_b, b, 0);
	for(int i=0;i<vertices;i++) 
	cout<<i+1<<" ";
	cout<<endl;
	for(int i=0;i<vertices;i++)
	cout<<max(distance_from_a[i], distance_from_b[i])<<" ";
	return 0; // return type is int 
}

void dfs(vector<vector<int>> &graph, vector<bool> &visited, int root,int &farthestRoot, int distance, int &maxDistance)
{
	visited[root] = true;
	distance +=1;
	for(auto u: graph[root])
	{
		if(!visited[u])
		{
			if(distance >= maxDistance)
			maxDistance = distance, farthestRoot = u;
			dfs(graph, visited, u, farthestRoot, distance, maxDistance);
		}
	}
}

void distance_dfs(vector<vector<int>> &graph, vector<bool> &visited, vector<int> &dist, int root, int current_distance)
{
	if(visited[root]) return;
	dist[root] = max(current_distance, dist[root]);
	visited[root] = true;
	
	for(auto u:graph[root])
	{
		if(!visited[u])
		{
			distance_dfs(graph, visited, dist, u, current_distance +1);
		}
	}
}
