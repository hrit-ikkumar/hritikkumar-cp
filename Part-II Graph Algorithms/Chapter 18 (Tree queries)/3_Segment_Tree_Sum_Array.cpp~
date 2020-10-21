// @hritikkumar

#include<bits/stdc++.h> // all header files

using namespace std; // namespace created as std

class SegmentTree
{
	public:
		vector<int> arr;
		vector<int> STarray;
	public:
		SegmentTree()
		{
			int n;
			cin>>n;
			arr.resize(n);
			for(int i=0;i<n;i++)
				cin>>arr[i];
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

int main(void)
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); // fastio
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	SegmentTree* ST = new SegmentTree();
	ST->constructST();
	ST->printArray();
	ST->printST();
	
	int start, end;
	cin>>start>>end;
	cout<<"SUM: "<<ST->sumQuery(start, end)<<endl;
	
	int update_index, update_value;
	cin>>update_index>>update_value;
	ST->updateST(update_index, update_value);
	ST->printArray();
	ST->printST();
	
	cin>>start>>end;
	cout<<"SUM: "<<ST->sumQuery(start, end)<<endl;
	
	return 0; // return type is int
}
