// @hritikkumar

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; // namespace created as std

// number of nodes with value x in given tree 
// We will use offline query here...

struct node
{
	int val;
	unordered_map<int, int> mp;
	
	node(){}
	node(int value)
	{
		val = value;
	}
};


class OfflineAlgoMapTree
{
	public:
		vector<pair<node*, vector<int>>> graph;
		int vertices, edges, head;
	public:
		OfflineAlgoMapTree()
		{
			cin	>>	this->vertices	>>	this->edges	>> 	this->head;
			graph.resize(vertices,{new node(), vector<int>()});
			for(int i=0;i<edges;i++)
			{
				int start, end;
				cin>>start>>end;
				graph[start].first = new node(start);
				graph[end].first = new node(end);
				graph[start].second.push_back(end);
			}
			
			dfs(this->head); // dfs for updating the values of map in order to improve the performance of algorithm
			
			
			print_everything();
		}
		
		void mergeMaps(unordered_map<int, int> & a, unordered_map<int, int> &b)
		{
			for(auto x: b)
			{
				a[x.first] += x.second;
			}
		} 
		
		unordered_map<int, int> dfsUtil(int root)
		{
			unordered_map<int, int> curr;
			curr[root] += 1;
			
			for(int x: graph[root].second)
			{
				unordered_map<int, int> childCurr = dfsUtil(x);
				mergeMaps(curr, childCurr);
			}
			return curr;
		}
		
		void dfs(int root)
		{
			unordered_map<int, int> dummy = dfsUtil( root);
		}
		
		void print_everything()
		{
			cout<<"GRAPH: "<<endl;
			for(auto x: graph)
			{
				cout<<(x.first)->val<<" => ";
				for(int y: x.second)
					cout<<y<<" ";
				cout<<endl;
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
	OfflineAlgoMapTree* tree = new OfflineAlgoMapTree();
	
	return 0; // return type is int
}
