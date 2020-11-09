// @hritikkumar

#include<bits/stdc++.h> // all header files

using namespace std; //  namespace created as std
// Hamiltonian Path is a path which visits each node once. This is NP-Hard problem. So, we have to solve it in polinomial time. 
// There are two solution for this problem
// 1. Backtracking O(n!)
// 2. DP O((2^n) * (n^2))
// Here we will code the backtracking one.

class HamiltonianPathGraph
{
	public:
		vector<vector<int>> graph; // adjacencey graph;
		vector<int> hamiltonianPath;
		int vertices, edges, start_node = 0;
	public:
		HamiltonianPathGraph() {}
		HamiltonianPathGraph(int v, int e, vector<vector<int>> Graph)
		{
			this->vertices = v;
			this->edges = e;
			this->graph = Graph;
		}
		
		void runScript()
		{
			printEverything();
			hamCycle();
		}
		
		bool isSafe(int v, int pos)
		{
			if(graph[hamiltonianPath[pos-1]][v] == 0)
				return false;
			for(int i = 0; i < pos; i++)
				if(hamiltonianPath[i] == v)
					return false;
			return true;
		}
		
		bool hamCycleUtil(int pos)
		{
			if(pos == this->vertices)
			{
				if(graph[hamiltonianPath[pos-1]][hamiltonianPath[0]] == 1)
					return true;
				else
					return false;
			}
			
			for(int v= 1; v < this->vertices; v++)
			{
				if(isSafe(v, pos))
				{
					hamiltonianPath[pos] = v;
					if(hamCycleUtil(pos+1))
						return true;
					hamiltonianPath[pos] = - 1;
				}
			}
			return false;
		}
		
		void hamCycle()
		{
			hamiltonianPath.resize(this->vertices, -1); // resize the answer vector
			
			hamiltonianPath[0] = 0;
			if(hamCycleUtil(1))
			{
				cout<<"HAMILTONIAN PATH: ";
				for(int x:hamiltonianPath)
					cout<<x<<" ";
				cout<<hamiltonianPath[0];
				cout<<endl;
			}
			else
			{
				cout<<"PATH DOESN'T EXIST!"<<endl;
			}
		}
		
		void printEverything()
		{
			cout<<"GRAPH: "<<endl;
			for(int node = 0; node < vertices; node++)
			{
				cout<<"NODE-"<<node<<": ";
				for(int	child = 0; child < vertices; child ++ )
					if(graph[node][child] == 1)
						cout<<child<<" ";
				cout<<endl;
			}
			cout<<endl; 
		}
};


int main(void)
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); // fastio
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	int v, e;
	cin>>v>>e;
	vector<vector<int>> GRAPH(v, vector<int>(v, 0));
	for(int i=0;i<e;i++)
	{
		int start, end;
		cin>>start>>end;
		GRAPH[start][end] = 1;
		GRAPH[end][start] = 1;
	}
	HamiltonianPathGraph* hamiltonianPathGraph = new HamiltonianPathGraph(v, e, GRAPH);
	hamiltonianPathGraph -> runScript();
	
	return 0; // return type is int 
}
