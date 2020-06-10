// @hritikkumar
#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std;

int maximumSumPathDP(int**, int);

int main(void)
{
	std::ios::sync_with_stdio(false); cin.tie(0); // fastio
	#ifndef ONLINE_JUDGE
	freopen("intput.txt", "r",stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	int n;
	cin>>n;
	int** grid = new int*[n];
	for(int i=0;i<n;i++) grid[i] = new int[n];
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>grid[i][j];
	int ans  = maximumSumPathDP(grid, n); // there is condition we can either move down or right
	// path from upper left corner to lower right corner
	cout<<ans<<endl;
	return 0; // return type is int
}

int maximumSumPathDP(int** grid, int n)
{
	int** dp_table = new int*[n];
	for(int i=0;i<n;i++) dp_table[i] = new int [n];
	
	for(int i=0;i<n;++i)
	{
		for(int j = 0;j<n;++j)
		{
			if( (i-1) >=0 && (j-1) >=0)
				dp_table[i][j] = max(dp_table[i-1][j], dp_table[i][j-1]) + grid[i][j];
			else if ( (i-1) >=0)
				dp_table[i][j] = dp_table[i-1][j] + grid[i][j];
			else if( (j-1) >=0)
				dp_table[i][j] = dp_table[i][j-1] + grid[i][j];
			else
				dp_table[i][j] = grid[i][j];
		}
	}
	return dp_table[n-2][n-2];
}
