// @hritikkumar

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; // namespace created as std

vector<vector<pair<int, int>>> kruskalMinimalSpanningTreeFun(priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> &, int);

int findParent(int root, vector<int> &parent)
{
	if(root == parent[root])
		return root;
	return findParent(parent[root], parent);
}

int main(void)
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); // fastio
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	int vertices, edges;
	cin>>vertices>>edges;
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> graph; // edge based graph representation
	for(int i=0;i<edges;i++)
	{
		int start, end, weight;
		cin>>start>>end>>weight;
		graph.push({weight, start, end});
	}
	vector<vector<pair<int, int>>> kruskalMinimalSpanningTree = kruskalMinimalSpanningTreeFun(graph, vertices);
	for(int i=0; i< (signed)kruskalMinimalSpanningTree.size();++i)
	{
		cout<<i<<": ";
		for(auto u: kruskalMinimalSpanningTree[i])
		{
			cout<<"{"<<u.first<<","<<u.second<<"}, ";
		}
		cout<<endl;
	}
	return 0; // return type is int
}

vector<vector<pair<int, int>>> kruskalMinimalSpanningTreeFun(priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> &graph, int vertices)
{
	vector<vector<pair<int, int>>> minimul_spanning_tree(vertices, vector<pair<int, int>>(0)); // minimum spanning tree graph
	vector<int> parent(vertices); 
	for(int i=0;i<vertices;i++) parent[i] = i;
	while(!graph.empty())
	{
		int start, end, weight;
		start = get<1>(graph.top()), end = get<2>(graph.top()), weight = get<0>(graph.top());
		graph.pop();
		cout<<start<<" "<<end<<" "<<weight<<endl;
		int startParent = findParent(start, parent), endParent = findParent(end, parent);
		if(startParent != endParent)
		{
			minimul_spanning_tree[start].push_back({end, weight});
			parent[startParent] = endParent;
		}
	}
	return minimul_spanning_tree;
}
