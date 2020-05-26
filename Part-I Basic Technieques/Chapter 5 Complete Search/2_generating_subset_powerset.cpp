// @hritikkumar
#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; //namespace created as std
void subsetPowerset(vector<vector<int>>&, int *, int );
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
	subsetPowerset(ans, a, n);
	for(vector<int> subset: ans)
	{
		for(int i=0;i<(signed)(subset.size()); i++)
		{
			cout<<subset[i]<<" ";
		}
		cout<<endl;
	}
	
	// Time Complexity O(2^n); 
	return 0; //return type is int
}


void subsetPowerset(vector<vector<int>> &ans, int* a, int n)
{
	for(int i=0;i<pow(2,n); ++i)
	{
		vector<int> subset;
		for(int j = 0;j<n;j++)
		{
			if(i & (1<<j))
			{
				subset.push_back(a[j]);
			}
		}
		ans.push_back(subset);
	}
}
