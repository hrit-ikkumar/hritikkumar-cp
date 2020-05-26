// @hritikkumar

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; //namespace created as std

vector<vector<int>> generatePermutation(int*, int);

int main(void)
{
	std::ios::sync_with_stdio(false); cin.tie(0);
	
	#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	int n;
	cin>>n;
	int* a= new int [n];
	for(int i=0;i<n;i++)cin>>a[i]; 
	
	vector<vector<int>> ans = generatePermutation(a, n);
	
	for(vector<int> permutation: ans)
	{
		for(int i=0;i<(signed) permutation.size(); ++i)
		cout<<permutation[i]<< " ";
		cout<<endl;
	}
	
	return 0; 
}

vector<vector<int>> generatePermutation(int *, int)
{
	vector<vector<int>> res;
	
	return res; 
}
