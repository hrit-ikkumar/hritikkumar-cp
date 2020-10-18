// @hritikkumar

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; // namespace created as std

class TreeAncestors
{
	private:
		vector<vector<int>> graph;
		vector<vector<int>> allAncestors;
	public:
		TreeAncestors(vector<vector<int>> graphOD)
		{
			this->graph = graphOD;
		}
		
		TreeAncestors()
		{
			// do nothing
		}
		
		void calcualteTreeAncestors()
		{
			allAncestors.resize(ceil(log2(graph.size())), vector<int>(graph.size()));
			
		}
		
		void printTreeAncestors()
		{
			cout<<"Tree Ancestors"<<endl;
			
			cout<<"			"<<endl;
			for(int i=0;i<(signed)allAncestors.size(); i++)
			{
				cout<<i+1<<" ";
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
			
			
			return 0;
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
	cin>>v>>e; // vertices & edges;
	vector<vector<int>> graphOD(v, vector<int>()); // graph for ordered direction
	
	for(int i=0;i<e;i++)
	{
		int start,end;
		cin>>start>>end;
		graphOD[start].push_back(end); // start -> end
	}
	
	TreeAncestors* treeAncestors = new TreeAncestors(graphOD); // pointer of TreeAncestors class 
	
	treeAncestors->calcualteTreeAncestors(); // calculate all the ancestors of  compressed length (kth in log(n))
	
	treeAncestors->printTreeAncestors(); // print the table of kth ancestors
	
	int x, k;
	cin>>x>>k; // kth ancestor of x
	int ans =   treeAncestors->kthAncestor(x, k);
	
	cout<<k<<(k<=3 ? "rd":"th")<<" Ancestor of  "<<x<<": "<<ans<<endl; // kth ancestor of x
	
	return 0; // return type is int 
}
