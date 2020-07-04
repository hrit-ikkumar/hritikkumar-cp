// @hritikkumar

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; // namespace created as std

vector<vector<long long int>> floydWarshallSPAlgorithm(vector<vector<int>> &, int ,int);

int main(void)
{
	std::ios::sync_with_stdio(false); // fastio
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	// O(n^3) == It gives us all the distance pair.
	int vertices, edges;
	cin>>vertices>>edges;
	vector<vector<int>> graph(vertices, vector<int>(vertices));
	for(int i=0;i<edges;i++)
	{
		int start, end, weight;
		cin>>start>>end>>weight;
		graph[start][end] = weight;
		graph[end][start] = weight;
	}
	vector<vector<long long int>> ans = floydWarshallSPAlgorithm(graph, vertices, edges);
	cout<<"  ";
	for(int i=0;i<vertices;i++)
		cout<<i<<" ";
	cout<<endl;
	for(int i=0;i<vertices;i++)
	{
		cout<<i<<":";
		for(int j=0;j<vertices;j++)
		cout<<ans[i][j]<<" ";
		cout<<endl;
	}
	return 0; // return type is int
}
vector<vector<long long int>> floydWarshallSPAlgorithm(vector<vector<int>> &graph, int vertices, int edges)
{
	vector<vector<long long int>> distance(vertices, vector<long long int>(vertices));
	for(int i=0;i<vertices;i++)
	{
		for(int j=0;j<vertices;j++)
		{
			if(i==j)
				distance[i][j] =0;
			else if(graph[i][j])
				distance[i][j] = (long long int)graph[i][j];
			else
				distance[i][j] = INT_MAX;
		}
	}
	for(int k=0;k<vertices;k++)
	{
		for(int i=0;i<vertices;i++)
		{
			for(int j=0;j<vertices;j++)
			{
				distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
			}
		}
	}
	
	return distance;
}
