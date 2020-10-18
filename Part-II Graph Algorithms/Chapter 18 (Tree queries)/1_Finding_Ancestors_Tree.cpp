// @hritikkumar

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; // namespace created as std

class TreeAncestors
{
	private:
		int head;
		vector<vector<int>> graph;
		vector<vector<int>> allAncestors;
	public:
		TreeAncestors(int root, vector<vector<int>> graphOD)
		{
			this->head = root;
			this->graph = graphOD;
		}
		
		TreeAncestors()
		{
			// do nothing
		}
		
		// x's kth ancestor
		/*int dfsKthAncestor(int root, int x, int k)
		{
			if(root == x)
			{
				return root;
			}
			else if(k == 0)
			{
				return -1;
			}
			
			int val = 0;
			for(int child: graph[root])
			{
				int currVal = dfsKthAncestor(child, x, k-1);
				if( currVal!= -1)
				{
					return 
				}
			}
		}
		*/
		void dfs(int root)
		{
			for(int x: graph[root])
			{
				allAncestors[0][x] = root;
				dfs(x);
			}
		}
		void calcualteTreeAncestors()
		{
			allAncestors.resize(ceil(log2(graph.size())), vector<int>(graph.size(), -1));
			dfs(head);
			for(int i=0;i<(signed)allAncestors[0].size();i++)
			{
				allAncestors[0][i] +=1;
			}
			for(int k=1;k<(signed)allAncestors.size();k++)
			{
				for(int node=0;node<(signed)allAncestors[k].size();node++)
				{
					// row is k term & col is x term 
					allAncestors[k][node] = allAncestors[k-1][allAncestors[k-1][node]-1]  ;
					
					if(allAncestors[k][node] <= -1)
						break;
				}
			}
		}
		
		void printTreeAncestors()
		{
			cout<<"Tree Ancestors"<<endl;
			
			cout<<"	";
			for(int i=0;i<(signed)allAncestors[0].size(); i++)
			{
				cout<<i<<" ";
			}
			cout<<endl;
			for(int i=0;i< (signed)allAncestors.size();i++)
			{
				cout<<(1<<i)<<":	";
				for(int j=0;j<(signed)allAncestors[i].size(); j++)
				{
					cout<<allAncestors[i][j]<<" ";
				}
				cout<<endl;
			}
		}
		
		int kthAncestor(int x, int k)
		{
			
			for(int i=0;i<(signed)allAncestors.size();i++)
			{
				if(k & (1 << i))
				{
					x = allAncestors[i][x-1] ;
						if(x == -1)
							break;
				}
			}
			return x;
		}
};

int main(void)
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); // fastio
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	int v, e, root;
	cin>>v>>e>>root; // vertices & edges;
	vector<vector<int>> graphOD(v, vector<int>()); // graph for ordered direction
	
	for(int i=0;i<e;i++)
	{
		int start,end;
		cin>>start>>end;
		graphOD[start].push_back(end); // start -> end
	}
	
	TreeAncestors* treeAncestors = new TreeAncestors(root,graphOD); // pointer of TreeAncestors class 
	
	treeAncestors->calcualteTreeAncestors(); // calculate all the ancestors of  compressed length (kth in log(n))
	
	treeAncestors->printTreeAncestors(); // print the table of kth ancestors
	
	int x, k;
	cin>>x>>k; // kth ancestor of x
	int ans =   treeAncestors->kthAncestor(x, k);
	
	cout<<k<<(k<=3 ? "rd":"th")<<" Ancestor of  "<<x<<": "<<ans<<endl; // kth ancestor of x
	
	return 0; // return type is int 
}
