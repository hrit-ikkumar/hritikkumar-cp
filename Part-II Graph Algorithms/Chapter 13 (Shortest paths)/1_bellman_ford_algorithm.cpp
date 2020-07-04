// @hritikkumar

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; // namespace created as std

vector<long long int> bellmanFordSPGraph(vector<tuple<int, int, int>> &, int, int);

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
	vector<tuple<int, int ,int>> graph_edges;//undirected & weighted
	for(int i=0;i<edges;i++)
	{
		int start, end, weight;
		cin>>start>>end>>weight;
		graph_edges.push_back({weight, start, end});
	}
	
	vector<long long int> ans = bellmanFordSPGraph(graph_edges, vertices, edges);
	cout<<"Vertices   Distance"<<endl;
	for(unsigned int i = 0;i<ans.size();i++)
	{
		cout<<i<<":         "<<ans[i]<<endl;
	}
	return 0; // return type is int
}

vector<long long int> bellmanFordSPGraph(vector<tuple<int, int, int>> &graph_edges, int vertices, int edges)
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
	return distance;
}
