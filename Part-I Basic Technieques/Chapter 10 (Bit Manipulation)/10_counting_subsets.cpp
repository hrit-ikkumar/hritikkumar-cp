// @hritikkumar

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; // namespace created as std

vector<int> countingSubsetSum(int );

int main(void)
{
	std::ios::sync_with_stdio(false); // fastio
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin>>n;
	vector<int> ans = countingSubsetSum(n);
	for(int i=0;i<(signed)ans.size();i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i &(1<<j))
				cout<<j<<" ";
		}
		cout<<" : "<<ans[i]<<endl;
	}
	return 0; // return type is int
}

vector<int> countingSubsetSum(int n)
{
	vector<int> sum(1<<n);
	for(int s=0;s<(1<<n); s++)
	{
		sum[s] = 
	}
}
