// @hritikkumar

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; // namespace created as std

int main(void)
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); // fastio
	#ifdef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	 
	int v, e, m; // m is no. of clauses 
	cin>>v>>m; // v -> total no. of nodes
	e = 2 * v; // edges = twice of vertices 
	vector<int> start, end; // start -> end clause, -ve sign means that that is complement of that node
	
	unordered<int, vector<int>> graph;
	for(int i=0;i<m;i++)
	{
		cin>>start[i]>>end[i];
	}
	
	// Convert the given sequence into map using map
	for(int i=0;i<m;i++)
	{
		graph[start[i]].push_back(end[i]); // start[i] -> end[i]
	}
	
}
