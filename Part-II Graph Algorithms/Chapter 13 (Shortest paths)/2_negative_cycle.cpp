
// @hritikkumar

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; // namespace created as std

bool negativeCycleBellmanFord(multiset<tuple<int, int, int>> &, int, int);

int main(void)
{
	std::ios::sync_with_stdio(false); // fastio
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	// If, There is any negative weight cycle in graph then it won't work!
	
	int vertices, edges;
	cin>>vertices>>edges;
	multiset<tuple<int, int ,int>> graph_edges;//undirected & weighted
	for(int i=0;i<edges;i++)
	{
		int start, end, weight;
		cin>>start>>end>>weight;
		graph_edges.insert({weight, start, end});
	}
	
	bool ans = negativeCycleBellmanFord(graph_edges, vertices, edges);
	if(ans) cout<<"Yes, There is a negative cycle!"<<endl;
	else	cout<<"No, There is no negative cycle!"<<endl;
	return 0; // return type is int
}

bool negativeCycleBellmanFord(multiset<tuple<int, int, int>> &graph_edges, int vertices, int edges)
{
	vector<long long int> distance(vertices, (long long int) INT_MAX);
	distance[0] = 0;
	for(int i=0;i<vertices -1;i++)
	{
		for(auto e: graph_edges)
		{
			int start, end, weight;
			tie(weight, start, end) = e;
			distance[end] = min(distance[end], distance[start] + weight);
		}
	}
	for(auto e: graph_edges)
	{
		int start, end, weight;
		tie(weight, start, end) = e;
		if(distance[end] > distance[start] + weight)
			return true;
	}
	return false;
}
