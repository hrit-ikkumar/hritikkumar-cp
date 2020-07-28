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
	for(int i=0;i<minimalSpanningTree.size();++i)
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
	
	
	
	return minimalSpanningTree;
}
