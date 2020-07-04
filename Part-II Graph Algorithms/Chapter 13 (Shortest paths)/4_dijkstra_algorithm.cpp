// @hritikkumar

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; // namespace created as std

vector<long long int> dijkstraSPGraph(vector<vector<pair<int, int>>> &, int , int );

int main(void)
{
	std::ios::sync_with_stdio(false); // fastio
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	// If, The weight is negative in that case it won't work.
	
	int vertices, edges; cin>>vertices>>edges;
	vector<vector<pair<int, int>>> graph(vertices);
	for(int i=0;i<edges;i++)
	{
		int start, end, weight;
		cin>>start>>end>>weight;
		graph[start].push_back({end, weight});
		graph[end].push_back({start, weight});
	}
	vector<long long int> ans = dijkstraSPGraph(graph, vertices, edges);
	cout<<"Vertices	Distance"<<endl;
	for(unsigned int i = 0;i<ans.size();i++)
	cout<<i<<"			"<<ans[i]<<endl;
	return 0; // return type is int
}

vector<long long int> dijkstraSPGraph(vector<vector<pair<int, int>>> &graph, int vertices, int edges)
{
	vector<bool> visited(vertices, false);
	vector<long long int> distance(vertices, (long long int) INT_MAX);
	distance[0] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({0,0}); // source from 0th node
	while(!pq.empty())
	{
		int start = pq.top().second; pq.pop();
		if(visited[start])	continue;
		visited[start] = true;
		for(auto u:graph[start])
		{
			int end, end_weight;
			tie(end, end_weight) = u;
			distance[end] = min(distance[end], distance[start] + end_weight);
			pq.push({-distance[end], end});
		}
	}
	return distance;
}
