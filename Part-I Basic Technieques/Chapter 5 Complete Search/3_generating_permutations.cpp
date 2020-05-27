// @hritikkumar

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; //namespace created as std

void recursivePermutation(vector<vector<int>>&, int *, int , vector<bool>, vector<int>);

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

void recursivePermutation(vector<vector<int>> &res, int *a, int n, vector<bool> chose, vector<int> current)
{
	if((signed)current.size()==n)
		{
			res.push_back(current);
			return;
		}
	for(int i=0;i<n;i++)
	{
		if(chose[i])
			continue;
		
		chose[i] = true;
		current.push_back(a[i]);
		recursivePermutation(res, a, n, chose, current);
		chose[i] = false;
		current.pop_back();
	}
}

vector<vector<int>> generatePermutation(int *a, int n)
{
	vector<vector<int>> res;
	vector<bool> chose(n, false);
	vector<int> current;
	recursivePermutation(res, a, n, chose, current); 
	return res; 
}
