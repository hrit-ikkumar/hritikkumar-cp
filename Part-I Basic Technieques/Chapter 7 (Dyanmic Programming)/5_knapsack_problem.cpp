// @hritikkumar

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std;

int knapsackDP(int*, int);

int main(void)
{
	std::ios::sync_with_stdio(false); cin.tie(0); // fastio
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	int n;
	cin>>n;
	int* weight = new int [n];
	for(int i=0;i<n;i++) cin>> weight[i];
	int ans = knapsackDP(weight, n);
	
	cout<<ans<<endl;
	
	return 0; // return type is int
}

int knapsackDP(int* weight, int n)
{
	int ans = 0;
	int total_sum = accumulate(weight, weight + n, 0);
	bool** dp_table = new bool*[total_sum+1];
	for(int i=0;i<=total_sum;++i)
		dp_table[i] = new bool[n+1];
	
	for(int i=0;i<=total_sum; ++i)
		for(int j=0;j<=n;j++)
			dp_table[i][j] = false;
	
	
	dp_table[0][0] = true;
	for(int k = 1; k<=n; k++)
	{
		for(int x = 0; x<=total_sum; ++x)
		{
			// weight index will be [k-1] for kth values in our choices
			if( (x - weight[k-1]) >= 0)
				dp_table[x][k] |= dp_table[x-weight[k-1]][k-1];
			dp_table[x][k] |= dp_table[x][k-1];
		}
	}
	
	for(int i=0; i<=total_sum; ++i)
	{
		if(dp_table[i][n])
			ans +=1;
	}
	
	return ans;
}
