
// @hritikkumar

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; // namespace created as std

vector<int> bfs(vector<vector<int>> &, int);

int main(void)
{
	std::ios::sync_with_stdio(false); // fastio
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r",stdin);
	freopen("output.txt", "w", stdout); 
	#endif
	
	int vertices, edges;
	cin>>vertices>>edges;
	vector<vector<int>> graph(vertices);
	while(edges--)
	{
		int start, end;
		cin>>start>>end;
		graph[start].push_back(end);
		graph[end].push_back(start);
	}
	
	vector<int> ans = bfs(graph, 0);
	for(int i=0;i<signed(ans.size());i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	return 0; // return type is int 
}

vector<int> bfs(vector<vector<int>> &graph,  int current)
{
	vector<bool> visited(graph.size(), false);
	vector<int> ans(0);
	
	queue<int> q; q.push(current);
	while(!q.empty())
	{
		if(!visited[q.front()])
		{
			ans.push_back(q.front()), visited[q.front()]=true;
			for(int i=0;i<(signed)graph[q.front()].size();i++)
			{
				if(!visited[graph[q.front()][i]])
					q.push(graph[q.front()][i]);
			}
		}
		q.pop();
	}
	return ans;
}
