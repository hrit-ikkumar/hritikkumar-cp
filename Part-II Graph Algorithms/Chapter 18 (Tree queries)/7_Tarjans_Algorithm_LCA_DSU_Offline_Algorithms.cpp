// @hritikkumar 

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; // namespace created as std

// Disjoint Set Union concept will be used in Tarjan's Algorithm

class DSU
{
	public:
		struct dsu_node
		{
			int parent=-1, rank;
			dsu_node() {}
			dsu_node(int p){parent = p;}
			dsu_node(int p, int r) {parent = p, rank = r;}
		};
		
		vector<dsu_node* > dsu;

	public:
		DSU(){}
		DSU(int size)
		{
			dsu.resize(size);
			for(int i=0;i<size;i++)
			{
				dsu[i] = new dsu_node(i, 0);
				
			}
			
			print_dsu();
		}
		
		int findDSU(int node)
		{
			if(dsu[node] -> parent != node)
			{
				dsu[node].parent = find(dsu[node].parent);
			}
			return dsu[node].parent;
		}
		
		void unionDSU(int node1, int node2)
		{
			int node1_root = find(node1),
				  node2_root = find(node2);
			
			if(dsu[node1_root]->rank < dsu[node2_root] ->rank)
				dsu[node1_root] -> parent = node2_root;
			else if(dsu[node1_root]->rank > dsu[node2_root]->rank)
				dsu[node2_root] -> parent = node2_root;
			else
			{
				dsu[node2_root] -> parent = node1_root;
				dsu[node1_root] -> rank += 1; // incremented the rank in DSU (Path compression technique is incorporated
			}
		}
		
		void print_dsu()
		{
			cout<<"DSU: ";
			for(int i = 0;i <(signed)dsu.size();i++)
			{
				cout<<"{"<<i<<" => ["<< dsu[i]->rank<<","<<dsu[i]->parent<<"]}"<<"	";
			}
			cout<<endl;
		}
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
			graph.resize(this->vertices);
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
			cout<<"PRINT"<<endl;
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
