// @hritikkumar

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; // namespace created as std

int countingSubgrids(vector<vector<int>> &);

int main(void)
{
	std::ios::sync_with_stdio(false); // fastio
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	int n;
	cin>>n;
	vector<vector<int>> color(n, vector<int>(n));
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>color[i][j];
	int ans = countingSubgrids(color);
	cout<<ans<<endl;
	return 0; // return type is int 
}

int countingSubgrids(vector<vector<int>> &color)
{
	int n = color.size();
	int ans = 0;
	for(int a=0; a<n; ++a)
	{
		for(int b=0; b<n; ++b)
		{
			int count = 0;
			for(int i=0;i<n;i++)
				if(color[a][i]==1 && color[b][i]==1) count++;
			ans += (count * (count -1))/2;
		}
	}
	/*
	 If, A row can be represented by a number(Binary).
	 * Then we can use __builtin_popcount function also.
	 * 	int count = 0;
		for (int i = 0; i <= n/N; i++) {
			count += __builtin_popcount(color[a][i]&color[b][i]);
		}
	 */
	return ans;
}
