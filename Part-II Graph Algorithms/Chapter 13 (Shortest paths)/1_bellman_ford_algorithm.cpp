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
	vector<vector<pair<int,int>>> graph(vertices);
	while(edges--)
	{
		int start, end, weight;
		cin>>start>>end>>weight;
		graph[start].push_back({end, weight});
		graph[end].push_back({start, weight});
	}
	
	return 0; // return type is int
}
