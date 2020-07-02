// @hritikkumar

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; // namespace created as std

vector<int> countingSubsetSum(vector<int> &, int );

int main(void)
{
	std::ios::sync_with_stdio(false); // fastio
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin>>n;
	vector<int> value(1<<n);
	for(int i=0;i<(1<<n); i++)	cin>>value[i];
	vector<int> ans = countingSubsetSum(value, n);
	for(int i=0;i<(signed)ans.size();i++)
	{
		cout<<"{";
		for(int j=0;j<n;j++)
		{
			if(i &(1<<j))
				cout<<j<<" ";
		}
		cout<<"}: "<<ans[i]<<endl;
	}
	return 0; // return type is int
}

vector<int> countingSubsetSum(vector<int> &value, int n)
{
	vector<int> sum(1<<n);
	for(int s=0;s<(1<<n); s++)
	{
		sum[s] = value[s];
	}
	for(int k=0;k<n;k++)
	{
		for(int s=0;s<(1<<n); s++)
		{
			if(s&(1<<k)) sum[s] += sum[s^(1<<k)];
		}
	}
	return sum;
}
