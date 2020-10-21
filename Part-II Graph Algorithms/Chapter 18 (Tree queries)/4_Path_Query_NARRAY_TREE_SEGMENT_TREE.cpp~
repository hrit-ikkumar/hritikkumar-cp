// @hritikkumar

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; // namespace created as std

class SegmentTree
{
	public:
		vector<int> arr, STarray, STlazy;
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
			STlazy.resize(ST_height, 0); // lazy propogation for range update

			buildST(0, arr.size() - 1, 0);	
		}
		
		int sumQueryUtil(int ST_start_range, int ST_end_range, int query_range_start, int query_range_end, int ST_index)
		{
			if(STlazy[ST_index] != 0)
			{
				STarray[ST_index] += (ST_end_range - ST_start_range + 1) * STlazy[ST_index];
				
				if(ST_start_range != ST_end_range)
				{
					STlazy[ST_index*2 + 1]  += STlazy[ST_index];
					STlazy[ST_index*2 + 2]  += STlazy[ST_index];
				}
				
				STlazy[ST_index] = 0;
			}
			
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
		
		void updateSTUtil(int ST_start_range, int ST_end_range, int start_index, int end_index, int difference, int ST_index)
		{
			
			if(STlazy[ST_index] != 0)
			{
				STarray[ST_index] += (ST_end_range - ST_start_range + 1)*STlazy[ST_index];
				if(ST_start_range != ST_end_range)
				{
					STlazy[ST_index * 2 + 1]  += STlazy[ST_index];
					STlazy[ST_index * 2 + 2] += STlazy[ST_index];
				}
				
				STlazy[ST_index]  = 0;
			}
			
			if(ST_start_range > ST_end_range || ST_start_range > end_index || ST_end_range < start_index)
				return;

			if(ST_start_range >= start_index &&  ST_end_range <= end_index)
			{
				STarray[ST_index] += (ST_end_range - ST_start_range + 1)*difference;
			
				if(ST_start_range != ST_end_range)
				{
					STlazy[ST_index * 2 + 1]  += difference;
					STlazy[ST_index * 2 + 2]  += difference;
				}
				return;
			}
			
			int mid = getMid(ST_start_range, ST_end_range);
			updateSTUtil(ST_start_range, mid, start_index, end_index, difference, 2*ST_index + 1);
			updateSTUtil(mid+1, ST_end_range,start_index, end_index, difference, 2*ST_index + 2);
			
			STarray[ST_index] = STarray[ST_index*2 + 1] + STarray[ST_index*2 + 2];
		}
		
		void updateST(int start_index, int end_index, int diff)
		{
			updateSTUtil(0, arr.size() -1 , start_index, end_index, diff, 0); 
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
		vector<int> arr, node_id, pathSum, subTreeSize;
		SegmentTree* segmentTree;
		int v, e, head;
	public:
		SubTreeQuery()
		{
			cin	>>	this->v	>>	this->e	>>	this->head	;
			graph.resize(v, vector<int>());
			for(int edge=0; edge < this->e; edge++)
			{
				int start, end;
				cin>>start>>end;
				graph[start].push_back(end);
			}
			bfs_arr(this->head);
			dfs_path(this->head, 0);
			segmentTree = new SegmentTree(pathSum);
		}
		
		int dfs_path(int root, int currSum)
		{
			currSum += root;
			node_id.push_back(root);
			pathSum.push_back(currSum);
			subTreeSize.push_back(1);
			int index = subTreeSize.size() - 1;
			int size = 0;
			for(int x: graph[root])
			{
				size += dfs_path(x, currSum);
			}
			subTreeSize[index] = size + 1;
			return 1 + size;
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
		
		void updateTREE(int node, int value)
		{
			int difference = value - pathSum[node];
			segmentTree -> updateST(node, node + subTreeSize[node] -1, difference);
		}
		
		int queryPathSum(int node)
		{
			return segmentTree->sumQuery(arr[node], arr[node]) ;
		}
		
		void print_tree()
		{
			cout<<"NODE_ID: 	";
			for(int x: node_id)
				cout<<x<<" ";
			cout<<endl;
			
			cout<<"SUB_TREE_SIZE: 	";
			for(int x: subTreeSize)
				cout<<x<<" ";
			cout<<endl;
			
			cout<<"PATH_SUM: 	";
			for(int x: pathSum)
				cout<<x<<" ";
			cout<<endl;
			
			cout<<"ARR: ";
			for(int x: arr)
				cout<<x<<" ";
			cout<<endl;
		}
		
		void print_everything()
		{
			print_tree();
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
	cout<<endl<<endl<<(st->queryPathSum(node))<<endl<<endl;
	st->updateTREE(node, value);
	cout<<endl<<endl<<(st->queryPathSum(node))<<endl<<endl;
	st->print_everything();
	return 0;
}
