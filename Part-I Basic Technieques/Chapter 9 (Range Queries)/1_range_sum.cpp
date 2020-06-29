// @hritikkumar

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; // namesapce created as std

int rangeSum(vector<int> &, int , int , int);

int main(void)
{
	std::ios::sync_with_stdio(false); // fastio
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r" , stdin);
	freopen("output.txt","w", stdout);
	#endif
	
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	int left, right;
	cin>>left>>right;
	int ans = rangeSum(a, n, left, right);
	cout<<ans<<endl; 
	
	return 0; // return type is int
}

int rangeSum(vector<int> &a, int n,  int left, int right)
{
	int sum = 0;
	for(int i=left; i<=right;i++)
		sum += a[i];
	return sum;
}
