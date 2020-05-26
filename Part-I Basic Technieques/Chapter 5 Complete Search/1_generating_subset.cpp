// @hritikkumar 
#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; // namespace created as std 

void subsetBacktracking(int*, vector<vector<int>>&, int , int , vector<int> ) ;

int main(void)
{
	std::ios::sync_with_stdio(false); cin.tie(0);
	
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	int n;
	cin>>n;
	
	int* a = new int[n];
	for(int i=0;i<n;i++)cin>>a[i];
	
	vector<vector<int>> ans;
	vector<int> curr(0);
	subsetBacktracking(a,ans, 0, n, curr);
	
	for(vector<int> subset : ans)
	{
		if(subset.size()==0)
		cout<<' ';
		else
		cout<<subset[0];
		for(int i=1;i<(signed)(subset.size());i++)
		{
			cout<<", "<<subset[i];
		}
		cout<<endl;
	}
	
	// Time complexity of this recurssion is O(2^n); 
	return 0; //return type is int
	
}

void subsetBacktracking(int *a, vector<vector<int>> &ans, int i, int n, vector<int> subset)
{
	if(i==n)
	{
		ans.push_back(subset);
		return;
	}
	// first exclude the element from the set
	// then include that element in the subset
	subset.push_back(a[i]);
	subsetBacktracking(a, ans, i+1, n, subset);
	subset.pop_back();
	subsetBacktracking(a, ans, i+1, n, subset);
}
