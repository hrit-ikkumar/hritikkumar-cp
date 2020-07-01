// @hritikkumar

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; // namespace created as std

int productSelectionDP(vector<vector<int>> &, int , int );

int main(void)
{
	std::ios::sync_with_stdio(false); // fastio
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	int k, n;
	cin>>k>>n;
	vector<vector<int>> a(k, vector<int>(n));
	for(int i=0;i<k;i++) for(int j=0;j<n;j++) cin>>a[i][j];
	int ans = productSelectionDP(a,k,n);
	cout<<ans<<endl;
	return 0; // return type is int
}

int productSelectionDP(vector<vector<int>> &a, int k, int n)
{
	vector<vector<int>> dp_table(1<<k, vector<int>(n));
	for(int x =0;x<k;++x)
		dp_table[1<<x][0] = a[x][0];
	
	for(int d = 1;d<n;d++)
	{
		for(int s = 0;s<(1<<k); s++)
		{
			dp_table[s][d] = dp_table[s][d-1];
			for(int x = 0;x<k;x++)
			{
				if(s&(1<<x))
					dp_table[s][d]  = min(dp_table[s][d], dp_table[s^(1<<x)][d-1] + a[x][d]);
			}
		}
	}
	return dp_table[(1<<k) - 1][n-1];
}
