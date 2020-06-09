// @hritikkumar

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; // namespace created as std

typedef long long ll;

int longestIncreasingSubseqenceDP(int *, int); // DP solution

int main(void)
{
	std::ios::sync_with_stdio(false); cin.tie(0); // fastio
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r",stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	int n;
	cin>>n;
	int* num = new int[n];
	for(int i=0;i<n;i++) cin>>num[i];
	
	cout<<longestIncreasingSubseqenceDP(num, n)<<endl;
	
	return 0; // retun type is int
}

int longestIncreasingSubseqenceDP(int *num, int n)
{
	int ans = 0;
	int* dp_table = new int[n];
	for(int i=0;i<n;i++)
	{
		dp_table[i] = 1;
		for(int j=0;j<i;j++)
		{
			// this condition for longest increasing which is different from longest non-decreasing (0 can be included)
			if(num[j] < num[i])
			{
				dp_table[i] = max(dp_table[i], dp_table[j] + 1);
			}
		}
		ans = max(ans, dp_table[i]);
	}
	return ans;
}
