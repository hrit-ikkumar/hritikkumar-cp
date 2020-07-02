// @hritikkumar

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; // namespace created as std

int main(void)
{
	std::ios::sync_with_stdio(false); // fastio
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	int edges, vertices;
	
	
	// Undirected & Unweighted Graph Representation
	cin>>vertices>>edges;
	vector<vector<int>> graph_und_unw(vertices, vector<int>(0));
	for(int i=0;i<edges;i++)
	{
		int start,end;
		cin>>start>>end;
		graph_und_unw[start].push_back(end);
		graph_und_unw[end].push_back(start);
	} // print it
	for(int i=0;i<vertices;i++)
	{
		cout<<i+1<<": ";
		for(int j=0;j<(signed)graph_und_unw[i].size();j++)
		{
			cout<<graph_und_unw[i][j]+1<<" ";
		}
		cout<<endl;
	} cout<<endl;
	
	// Directed & Unweighted Graph Representation
	cin>>vertices>>edges;
	vector<vector<int>> graph_d_unw(vertices, vector<int>(0));
	for(int i=0;i<edges;i++)
	{
		int start,end;
		cin>>start>>end;
		graph_d_unw[start].push_back(end);
	} // print it
	for(int i=0;i<vertices;i++)
	{
		cout<<i+1<<": ";
		for(int j=0;j<(signed)graph_d_unw[i].size();j++)
		{
			cout<<graph_d_unw[i][j]+1<<" ";
		}
		cout<<endl;
	}cout<<endl;
	
	
	// Undirected & Weighted Graph Representation
	cin>>vertices>>edges;
	vector<vector<pair<int, int>>> graph_und_w(vertices, vector<pair<int, int>>());
	for(int i=0;i<edges;i++)
	{
		int start, end, weight;
		cin>>start>>end>>weight;
		graph_und_w[start].push_back({end, weight});
		graph_und_w[end].push_back({start, weight});
	} // print it
	for(int i=0;i<vertices;i++)
	{
		cout<<i+1<<": ";
		for(int j=0;j<(signed)graph_und_w[i].size();j++)
		{
			cout<<graph_und_w[i][j].first+1<<"{"<<graph_und_w[i][j].second<<"} ";
		}
		cout<<endl;
	} cout<<endl;
	
	// Directed & Weighted Graph Representation
	cin>>vertices>>edges;
	vector<vector<pair<int, int>>> graph_d_w(vertices, vector<pair<int, int>>());
	for(int i=0;i<edges;i++)
	{
		int start, end, weight;
		cin>>start>>end>>weight;
		graph_d_w[start].push_back({end, weight});
	} // print it
	for(int i=0;i<vertices;i++)
	{
		cout<<i+1<<": ";
		for(int j=0;j<(signed)graph_d_w[i].size();j++)
		{
			cout<<graph_d_w[i][j].first+1<<"{"<<graph_d_w[i][j].second<<"} ";
		}
		cout<<endl;
	} cout<<endl;
	
	return 0; // return type is int
}
