// @hritikkumar

#include<bits/stdc++.h> // all header files

#define end '\n'

using namespace std; // namespace created as std

class LCA
{
	public:
		vector<vector<int>> graph;
		vector<int> dfs_seq, depth_seq;
		int vertices, edges, head;
	public:
		LCA()
		{
			cin	>> this->vertices	>>	this->edges	>>	this->head	;
			
			for(int currEdge = 0; currEdge < edges; currEdge++)
			{
				int start, end;
				cin>>start>>end;
				
				graph[start].push_back(end);
			}
		}
};

int main(void)
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); // fastio
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	 
	 LCA* lca = new LCA();
	 
	 return 0; // return type is int
}
