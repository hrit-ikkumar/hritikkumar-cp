// @hritikkumar

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; // namespace created as std

int sparseTableMinimumQuery(vector<int> &, int, int , int);

int main(void)
{
	std::ios::sync_with_stdio(false); // fastio
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	int left, right;
	cin>>left>>right;
	int ans = sparseTableMinimumQuery(a, n, left, right);
	cout<<ans<<endl; 
	return 0; // return type is int
}

int sparseTableMinimumQuery(vector<int> &a, int n, int left, int right)
{
	int row = n, col = (log(n)/log(2)) + 1;
	vector<vector<int>> lookup_table(row, vector<int>(col, 0));
	for(int i=0;i<row;i++)	lookup_table[i][0] = i;
	for(int j=1;(1<<j) <= n; j++)
	{
		for(int i = 0;(i+(1<<j) -1) < n;i++)
		{
			if(a[lookup_table[i][j-1]] < a[lookup_table[i +(1<<(j-1))][j-1]])
				lookup_table[i][j] = lookup_table[i][j-1];
			else
				lookup_table[i][j] = lookup_table[i + (1<<(j-1))][j-1];
		}
	}
	int k = log2(right - left + 1);
	return min(a[lookup_table[left][k]] , a[lookup_table[right - (1<<k) + 1][k]]);
}
