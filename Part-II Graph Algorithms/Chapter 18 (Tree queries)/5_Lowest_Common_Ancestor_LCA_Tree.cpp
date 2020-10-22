// @hritikkumar

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; // namespace created as std

class SegmentTreeMin
{
	public:
		vector<int> STarry, arr;
	
	public:
		SegmentTreeMin(vector<int> a)
		{
			this->arr = a;
			constructST();
		}
		
		int getMid(int start, int end)
		{
			return start + (end - start) /2 ;
		}
		
		void buildST(int ST_start_range, int ST_end_range, int ST_index)
		{
			if(ST_start_range != ST_end_range)
			{
				int mid = getMid(ST_start_range, ST_end_range);
				buildST(ST_start_range, mid, ST_index*2 + 1);
				buildST(mid + 1, ST_end_range, ST_index*2 + 2);
				
				STarry[ST_index] = min(STarry[ST_index*2 + 1], STarry[ST_index*2 + 2]);
			}
			else
			{
				STarry[ST_index] = arr[ST_start_range];
				return;
			}
		}
		
		void constructST()
		{
			int height = ceil( log2(arr.size()) );
			STarry.resize(2*pow(2, height) + 1, 0); // segment tree;
			buildST(0, arr.size() - 1, 0);
		}
		
		int minUtil(int ST_start_range, int ST_end_range, int start_index, int end_index, int ST_index)
		{
			if(ST_start_range > ST_end_range || ST_start_range > end_index || ST_end_range < start_index)
				return INT_MAX;
			
			if(ST_start_range >= start_index && ST_end_range <= end_index)
			{
				return STarry[ST_index];
			}
			
			int mid = getMid(ST_start_range, ST_end_range);
			return min(minUtil(ST_start_range, mid, start_index, end_index, 2*ST_index + 1),
											minUtil(mid+1, ST_end_range, start_index, end_index, 2*ST_index + 2)	);
		}
		
		int queryMin(int start_index, int end_index)
		{
			return minUtil(0, arr.size() -1, start_index, end_index, 0);
		}
		
		
		void print_st()
		{
			cout<<"STarray: ";
			for(int x: STarry)
				cout<<x<<" ";
			cout<<endl;
			
			cout<<"ARR: ";
			for(int x: arr)
				cout<<x<<" ";
			cout<<endl;
		}
};

class LCA
{
	public:
		vector<vector<int>> graph;
		vector<int> dfs_seq, depth_seq;
		int vertices, edges, head;
		
		SegmentTreeMin* segmentTree;
	public:
		LCA()
		{
			cin	>> this->vertices	>>	this->edges	>>	this->head	;
			graph.resize(this->vertices, vector<int>());
			for(int currEdge = 0; currEdge < edges; currEdge++)
			{
				int start, end;
				cin>>start>>end;
				
				graph[start].push_back(end);
			}
			
			dfs(this->head,1);
			segmentTree = new SegmentTreeMin(depth_seq);
		}
		
		void dfs(int root, int level)
		{
			dfs_seq.push_back(root);
			depth_seq.push_back(level);
			for(int x: graph[root])
			{
				dfs(x, level + 1);
			}
			dfs_seq.push_back(root);
			depth_seq.push_back(level);
		}
		
		int query(int node1 , int node2)
		{
			return segmentTree->queryMin(node1, node2);
		}
		void print_eveything()
		{
			cout<<"DFS_SEQ: 		";
			for(int x: dfs_seq)
				cout<<x<<" ";
			cout<<endl;
			
			cout<<"DEPTH_SEQ: 	";
			for(int x: depth_seq)
				cout<<x<<" ";
			cout<<endl;
			
			segmentTree -> print_st();
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
	 lca->print_eveything();
	 
	 int n1, n2;
	 cin>>n1>>n2;
	 cout<< lca->query(n1, n2) << endl;
	 
	 return 0; // return type is int
}
