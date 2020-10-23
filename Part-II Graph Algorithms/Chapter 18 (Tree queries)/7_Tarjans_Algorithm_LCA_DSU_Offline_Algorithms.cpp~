// @hritikkumar 

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; // namespace created as std

// Disjoint Set Union concept will be used
struct dsu_node
{
	int parent, rank;
	dsu_node() {}
	dsu_node(int p){parent = p;}
	dsu_node(int p, int r) {parent = p, rank = r;}
};


class LCA_OFFLINE
{
	public:
		// data members
		vector<vector<int>> graph;
		int vertices, edges, head;
	
	public:
		LCA_OFFLINE()
		{
			// default values will be set here
			cin	>>	this->vertices 	>>	this->edges	>> this->head;
			for(int i=0;i<edges;i++)
			{
				int start, end;
				cin>>start>>end;
				graph[start].push_back(end); // adjacency list rep
			}
			
			print_everything(); // for debugging purpose
		}
		
		void print_everything()
		{
			// all the priting part will be done here...
		}
};

int main(void)
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); // fastio
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	LCA_OFFLINE *lca = new LCA_OFFLINE();
	
	return 0; // return type is int
}
