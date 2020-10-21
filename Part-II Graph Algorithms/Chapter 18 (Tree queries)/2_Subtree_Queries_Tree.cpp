// @hritikkumar

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; // namespace created as std

class SegmentTree
{
	public:
		vector<int> arr;
		vector<int> STarray;
	public:
		SegmentTree(vector<int> a)
		{
			this->arr = a;
			constructST();
			
		}
		SegmentTree()
		{
			// do nothing
		}
		
		int getMid(int start, int end)
		{
			return start + (end - start) / 2;
		}
		
		int buildST(int ST_start_range, int ST_end_range, int ST_index)
		{
			if(ST_start_range == ST_end_range)
			{
				STarray[ST_index] = arr[ST_start_range];
				return STarray[ST_index];
			}
			
			int mid = getMid(ST_start_range, ST_end_range);
			
			STarray[ST_index] = buildST(ST_start_range, mid, 2*ST_index + 1)
											+ buildST(mid + 1, ST_end_range, 2*ST_index + 2);
			return STarray[ST_index];
		}
		
		void constructST()
		{
			int height = ceil(log2(arr.size())) ;
			
			int ST_height = 2 * pow(2, height) - 1; // 2n - 1;
			STarray.resize(ST_height, 0); // new height set
			
			buildST(0, arr.size() - 1, 0);	
		}
		
		int sumQueryUtil(int ST_start_range, int ST_end_range, int query_range_start, int query_range_end, int ST_index)
		{
			// CASE-1: Segment Tree Range is inside the query range (just return the usm of that range)
			if(ST_start_range >= query_range_start && ST_end_range <= query_range_end)
			{
				return STarray[ST_index];
			}
			
			// CASE-2: Segment Tree Range is outside the query range (just return 0 because that doesn't contain any value of query range
			else if(ST_start_range > query_range_end || ST_end_range < query_range_start)
			{
				return 0;
			}
			
			// CASE-3: Partial range intersaction in given query
			
			int mid = getMid(ST_start_range, ST_end_range);
			return sumQueryUtil(ST_start_range, mid, query_range_start, query_range_end, 2 * ST_index + 1)
						+ sumQueryUtil(mid + 1, ST_end_range, query_range_start, query_range_end, 2 * ST_index + 2);
		}
		
		int sumQuery(int range_start, int range_end)
		{
			if(range_start < 0 || range_end > (signed) arr.size() - 1 || range_start > range_end)
			{
				return -1 ; // invalid query 
			}
			
			return sumQueryUtil(0, arr.size() - 1, range_start, range_end, 0);
		}
		
		void updateSTUtil(int ST_start_range, int ST_end_range, int arr_index, int difference, int ST_index)
		{
			if(arr_index < ST_start_range || arr_index > ST_end_range)
				return;
			
			STarray[ST_index] += difference;
			
			if(ST_start_range != ST_end_range)
			{
				int mid = getMid(ST_start_range, ST_end_range);
				updateSTUtil(ST_start_range, mid, arr_index, difference, 2*ST_index + 1);
				updateSTUtil(mid+1, ST_end_range, arr_index, difference, 2*ST_index + 2);
			}
		}
		
		void updateST(int arr_index, int newValue)
		{
			int difference = newValue - arr[arr_index] ;
			arr[arr_index] = newValue;
			updateSTUtil(0, arr.size() -1 , arr_index, difference, 0); 
		}
		
		void printArray()
		{
			cout<<"ARRAY: ";
			for(int x: arr)
				cout<<x<<" ";
			cout<<endl;
		}
		
		void printST()
		{
			cout<<"ST: ";
			for(int x: STarray)
				cout<<x<<" ";
			cout<<endl;
		}
};

class SubTreeQuery
{
	public:
		vector<vector<int>> graph;
		vector<int> dfs_sequence;
		vector<pair<int, int>> dfs_timing;
		vector<int> arr;
		SegmentTree* segmentTree;
		int v, e, head;
	public:
		SubTreeQuery()
		{
			cin>>this->v>>this->e>>this->head;
			graph.resize(v, vector<int>());
			for(int edge=0; edge < this->e; edge++)
			{
				int start, end;
				cin>>start>>end;
				graph[start].push_back(end);
			}
			dfs_timing.resize(this->v, {0,0}); // timing is just only the incoming and outgoing time of a node
			
			dfs_sequence_fun(this->head);
			dfs_timing_fun();
			bfs_arr(this->head);
			segmentTree = new SegmentTree(dfs_sequence);
		}
		
		void bfs_arr(int root)
		{
			queue<int> q;
			q.push(root);
			
			while(!q.empty())
			{
				int size = q.size();
				while(size--)
				{
					int curr = q.front(); q.pop();
					arr.push_back(curr);
					for(int x: graph[curr])
					{
						q.push(x);
					}
				}
			}
		}
		void dfs_sequence_fun(int root)
		{
			dfs_sequence.push_back(root);
			for(int x: graph[root])
			{
				dfs_sequence_fun(x); 
			}
			dfs_sequence.push_back(root);
		}
		
		void dfs_timing_fun()
		{
			for(int i=0;i<(signed)dfs_sequence.size();i++)
			{
				if(dfs_timing[dfs_sequence[i]].first == 0)
				{
					dfs_timing[dfs_sequence[i]].first = i+ 1;
				}
				else
				{
					dfs_timing[dfs_sequence[i]].second = i + 1;
				}
			}
		}
		
		void updateTREE(int node, int value)
		{
			arr[node] = value;
			segmentTree -> updateST(dfs_timing[node].first -1, value);
			segmentTree-> updateST(dfs_timing[node].second - 1, value);
		}
		
		int querySubtreeSum(int node)
		{
			return segmentTree->sumQuery(dfs_timing[node].first -1, dfs_timing[node].second - 1) / 2;
		}
		
		
		void print_dfs_timing()
		{
			cout<<"DFS TIMING: "<<endl;
			for(int i=0;i<(signed)dfs_timing.size();i++)
			{
				cout<<i<<": "<<dfs_timing[i].first<<"  	<-->  "<<dfs_timing[i].second<<endl;
			}
		}
		void print_dfs_sequence()
		{
			cout<<"DFS: ";
			for(int x:dfs_sequence)
				cout<<x<<" ";
			cout<<endl;
		}
		void print_arr()
		{
			cout<<"ARR: ";
			for(int x: arr)
				cout<<x<<" ";
			cout<<endl;
		}
		
		void print_everything()
		{
			print_dfs_sequence();
			print_dfs_timing();
			print_arr();
			segmentTree->printArray();
			segmentTree->printST();
		}
};

int main(void)
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); // fast io
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	SubTreeQuery* st = new SubTreeQuery();
	st->print_everything();
	
	int node, value;
	cin>>node >> value;
	cout<<(st->querySubtreeSum(node))<<endl;
	st->updateTREE(node, value);
	cout<<(st->querySubtreeSum(node))<<endl;
	st->print_everything();
	return 0;
}
