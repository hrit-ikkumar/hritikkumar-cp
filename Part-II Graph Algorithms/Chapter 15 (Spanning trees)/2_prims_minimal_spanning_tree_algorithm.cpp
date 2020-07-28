// @hritikkumar 

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; // namespace created as std

vector<vector<pair<int, int>>> primsAlgorithm(vector<vector<pair<int, int>>> &, int);

int main(void)
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); // fastio
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r",stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int vertices, edges;
	cin>>vertices>>edges;
	vector<vector<pair<int, int>>> graph(vertices, vector<pair<int, int>>(0));
	for(int i=0;i<edges;i++)
	{
		int start, end, weight;
		cin>>start>>end>>weight;
		graph[start].push_back({end, weight});
	}
	vector<vector<pair<int, int>>> minimalSpanningTree = primsAlgorithm(graph, vertices);
	for(int i=0;i<(signed) minimalSpanningTree.size();++i)
	{
		cout<<i<<": ";
		for(auto u: minimalSpanningTree[i])
		{
			cout<<"{"<<u.first<<", "<<u.second<<"} ";
		}
		cout<<endl;
	}
	return 0; // return type is int
}

vector<vector<pair<int, int>>> primsAlgorithm(vector<vector<pair<int, int>>> &graph, int vertices)
{
	vector<vector<pair<int, int>>> minimalSpanningTree(vertices, vector<pair<int, int>>(0));
	
	int source = 0;
	vector<int> key(vertices, INT_MAX);
	vector<int> parent(vertices, -1); 
	vector<bool> visited(vertices, false);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	
	pq.push({0, source});
	key[source] = 0;
	
	while(!pq.empty())
	{
		int start = pq.top().second; pq.pop();
		visited[start] = true;
		for(auto u: graph[start])
		{
			int end = u.first, weight = u.second;
			if(!visited[end] && key[end] > weight)
			{
				key[end] = weight;
				pq.push({key[end], end});
				parent[end] = start;
			}
		}
	}
	return minimalSpanningTree;
}
