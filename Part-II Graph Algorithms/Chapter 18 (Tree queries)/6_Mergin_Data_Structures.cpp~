// @hritikkumar

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; // namespace created as std

// number of nodes with value x in given tree 
// We will use offline query here...

struct node
{
	int node_val;
	int val;
	unordered_map<int, int> mp;
	
	node(){}
	node(int value)
	{
		val = value;
	}
	node(int value, int nodeVal)
	{
		val = value;
		node_val = nodeVal;
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
				int start_node, start_val, end_node, end_val;
				cin>>start_node>>start_val>>end_node>>end_val;
				graph[start_node].first = new node(start_node, start_val);
				graph[end_node].first = new node(end_node, end_val);
				graph[start_node].second.push_back(end_node);
			}
			
			dfs(this->head); // dfs for updating the values of map in order to improve the performance of algorithm
			
			
			print_everything();
		}
		
		int query(int node, int subNode)
		{ 
			return graph[node].first -> mp [subNode];
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
			curr[graph[root].first -> node_val] += 1;
			
			for(int x: graph[root].second)
			{
				unordered_map<int, int> childCurr = dfsUtil(x);
				mergeMaps(curr, childCurr);
			}
			graph[root].first -> mp = curr;
			return curr;
		}
		
		void dfs(int root)
		{
			graph[root].first -> mp = dfsUtil( root);
		}
		
		void print_everything()
		{
			cout<<"GRAPH: "<<endl;
			for(auto x: graph)
			{
				cout<<(x.first)->val<<" => ";
				cout<<"{";
				for(auto t: x.first -> mp)
					cout<<"["<<t.first<<", "<<t.second<<"],";
				cout<<"}  ::::   ";
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
	int NODE, SUBNODE;
	cin>>NODE>>SUBNODE;
	cout<<"ans: "<<tree->query(NODE, SUBNODE)<<endl;
	return 0; // return type is int
}
