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
	
	int vertices, edges;
	
	// Undirected & Unweighted Graph Representation
	cin>>vertices>>edges;
	vector<vector<int>> graph_und_unw(vertices, vector<int>(vertices, 0));
	for(int i=0;i<edges;i++)
	{
		int start,end;
		cin>>start>>end;
		graph_und_unw[start][end]=graph_und_unw[end][start]=1;
	} // print it
	cout<<"  ";
	for(int i=0;i<vertices;i++)
	cout<<i+1<<" ";
	cout<<endl;
	for(int i=0;i<vertices;i++)
	{
		cout<<i+1<<":";
		for(int j=0;j<vertices;j++)
		{
			cout<<graph_und_unw[i][j]<<" ";
		}
		cout<<endl;
	} cout<<endl;
	
	// Directed & Unweighted Graph Representation
	cin>>vertices>>edges;
	vector<vector<int>> graph_d_unw(vertices, vector<int>(vertices, 0));
	for(int i=0;i<edges;i++)
	{
		int start,end;
		cin>>start>>end;
		graph_d_unw[start][end]=1;
	} // print it
	cout<<"  ";
	for(int i=0;i<vertices;i++)
	cout<<i+1<<" ";
	cout<<endl;
	for(int i=0;i<vertices;i++)
	{
		cout<<i+1<<":";
		for(int j=0;j<vertices;j++)
		{
			cout<<graph_d_unw[i][j]<<" ";
		}
		cout<<endl;
	} cout<<endl;

	// Undirected & Weighted Graph Representation
	cin>>vertices>>edges;
	vector<vector<int>> graph_und_w(vertices, vector<int>(vertices, 0));
	for(int i=0;i<edges;i++)
	{
		int start,end, weight;
		cin>>start>>end>>weight;
		graph_und_w[start][end]=graph_und_w[end][start]=weight;
	} // print it
	cout<<"  ";
	for(int i=0;i<vertices;i++)
	cout<<i+1<<" ";
	cout<<endl;
	for(int i=0;i<vertices;i++)
	{
		cout<<i+1<<":";
		for(int j=0;j<vertices;j++)
		{
			cout<<graph_und_w[i][j]<<" ";
		}
		cout<<endl;
	} cout<<endl;
	
	// Directed & Weighted Graph Representation
	cin>>vertices>>edges;
	vector<vector<int>> graph_d_w(vertices, vector<int>(vertices, 0));
	for(int i=0;i<edges;i++)
	{
		int start,end, weight;
		cin>>start>>end>>weight;
		graph_d_w[start][end]=weight;
	} // print it
	cout<<"  ";
	for(int i=0;i<vertices;i++)
	cout<<i+1<<" ";
	cout<<endl;
	for(int i=0;i<vertices;i++)
	{
		cout<<i+1<<":";
		for(int j=0;j<vertices;j++)
		{
			cout<<graph_d_w[i][j]<<" ";
		}
		cout<<endl;
	} cout<<endl;

	return 0; // return type is int
}
