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
	cin>>vertices>>edges;
	vector<vector<int>> graph(vertices, vector<int>());
	for(int i=0;i<edges;i++)
	{
		int start, end;
		cin>>start>>end;
		graph[start].push_back(end);
	}
	
}
