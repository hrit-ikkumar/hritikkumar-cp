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
				dsu[node]->parent = findDSU(dsu[node]->parent);
			}
			return dsu[node]->parent;
		}
		
		void unionDSU(int node1, int node2)
		{
			int node1_root = findDSU(node1),
				  node2_root = findDSU(node2);
			
			if(dsu[node1_root]->rank < dsu[node2_root] ->rank)
				dsu[node1_root] -> parent = node2_root;
			else if(dsu[node1_root]->rank > dsu[node2_root]->rank)
				dsu[node2_root] -> parent = node2_root;
			else
			{
				dsu[node1_root] -> parent = node2_root;
				dsu[node2_root] -> rank += 1; // incremented the rank in DSU (Path compression technique is incorporated
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
		vector<vector<int>> queries;
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
			takeInputQueries();
			dfsMaster(this->head);
			print_everything(); // for debugging purpose
		}
		
		void dfs(vector<int> &ancestor, vector<bool> &visited, int root, DSU *dsu_ds)
		{
			visited[root] = true;
			ancestor[root] = root;
			for(int v : graph[root])
			{
				if(!visited[v])
				{
					dfs(ancestor, visited, v, dsu_ds);
					dsu_ds->unionDSU(root, v);
					ancestor[dsu_ds->findDSU(root)] = root;
				}
			}
			for(int other_node: queries[root])
			{
				if(visited[other_node])
				{
					cout<<"LCA of "<<root<<" and "<<other_node<<" is " <<ancestor[dsu_ds->findDSU(other_node)] << "."<<endl;
				}
			}
		}
		
		void dfsMaster(int root)
		{
			vector<int> ancestor(this->vertices, this->head);
			vector<bool> visited(this->vertices, false);
			DSU *dsu_ds = new DSU(this->vertices);
			dfs(ancestor, visited, root, dsu_ds);
			dsu_ds -> print_dsu();
		}
		
		void takeInputQueries()
		{
			int totalQuery;
			cin>>totalQuery;
			queries.resize(this->vertices);
			while(totalQuery--)
			{
				int first, second;
				cin>>first>>second;
				queries[first].push_back(second);
				queries[second].push_back(first);
			}
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
