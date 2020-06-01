// @hritikkumar

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; //namespace created as std

void permutations(vector<vector<int>> &, int *, int );

vector<vector<int>> generatePermutationsSTL(int *, int );

int main(void)
{
	std::ios::sync_with_stdio(false); cin.tie(0); 
	
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt" , "w", stdout);
	#endif
	
	int n;
	cin>>n;
	int* a = new int[n];
	for(int i=0;i<n;i++)cin>>a[i];
	
	vector<vector<int>> ans = generatePermutationsSTL(a, n);
	
	for(vector<int> permu: ans)
	{
		for(int i=0;i<(signed)permu.size();i++)
		{
			cout<<permu[i]<< " ";
		}
		cout<<endl;
	}
	
	return 0; //return type is int
}

void permutations(vector<vector<int>> &res, int *a, int n)
{
	vector<int> currentPermu;
	for(int i=0;i<n;i++)
		currentPermu.push_back(a[i]);
	
	do{
		res.push_back(currentPermu);
	}
	while(next_permutation(currentPermu.begin(), currentPermu.end()));
}


vector<vector<int>> generatePermutationsSTL(int *a, int n)
{
	vector<vector<int>> res;
	permutations(res, a, n);
	
	return res;
	
}
