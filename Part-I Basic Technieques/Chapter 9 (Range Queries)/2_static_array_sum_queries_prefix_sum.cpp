// @hritikkumar

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; // namespace created as std

int staticRangeQuery1D(vector<int> &, int , int , int);

int staticRangeQuery2D(vector<int> &, int , int , int);

int main(void)
{
	std::ios::sync_with_stdio(false); // fastio
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt","w",stdout);
	#endif
	int n;
	cin>>n;
	vector<int> a(n,0);
	for(int i=0;i<n;i++) cin>>a[i];
	int left, right;
	cin>>left>>right;
	int ans = staticRangeQuery1D(a, n, left, right);
	cout<<ans<<endl;
	
	return 0; // return type is int
}

int staticRangeQuery1D(vector<int> &a, int n, int left, int right)
{
	vector<int> prefix_sum(n, 0);
	prefix_sum[0] = a[0];
	for(int i=1;i<n;i++) prefix_sum[i] = prefix_sum[i-1] + a[i];
	
	return (prefix_sum[right] - prefix_sum[left-1]);
}
