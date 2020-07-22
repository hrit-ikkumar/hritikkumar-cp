// @hritikkumar

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; // namespace created as std

void dfs(vector<vector<int>> &,vector<int> &,  int );

int treeDiameter(vector<vector<int>> &, vector<int> &);
int main(void)
{
	std::ios::sync_with_stdio(false); // fastio
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int vertices, edges;
	cin>>vertices>>edges;
	vector<vector<int>> graph(vertices,vector<int>());
	for(int i=0;i<edges;i++)
	{
		int start, end;
		cin>>start>>end;
		graph[start].push_back(end);
		graph[end].push_back(start);
	}
	vector<int> toLeaf(vertices, 0), maxLength(vertices, 0);
	
	dfs(graph,toLeaf, 0);
	int ans = treeDiameter(graph, toLeaf);
	cout<<ans<<endl;
	return 0; // return type is int
}

void dfs(vector<vector<int>> &graph,vector<int>  &toLeaf, int current)
{
	for(auto u:graph[current])
	{
		dfs(graph,toLeaf, u);
		toLeaf[current] = max(toLeaf[current], toLeaf[u] + 1);
	}
}

int treeDiameter(vector<vector<int>> &graph, vector<int> &toLeaf)
{
	vector<int> height(graph.size(), 0);
	for(int i=0;i<(signed)graph.size();i++)
	{
		if(graph[i].size()==0)
			height[i] = 0;
		else if(graph[i].size()==1)
			height[i] = toLeaf[graph[i][0]] + 1;
		else
		{
			int max1 = toLeaf[graph[i][0]], max2 = INT_MIN;
			for(int j=1;j<(signed)graph[i].size();j++)
			{
				if(toLeaf[graph[i][j]] > max1)
				{
					max2 = max1;
					max1 = toLeaf[graph[i][j]];
				}
				else if(toLeaf[graph[i][j]] > max2)
				{
					max2 = toLeaf[graph[i][j]];
				}
			}
			height[i] = max1 + max2 + 2;
		}
	}
	return *max_element(height.begin(), height.end());
}
