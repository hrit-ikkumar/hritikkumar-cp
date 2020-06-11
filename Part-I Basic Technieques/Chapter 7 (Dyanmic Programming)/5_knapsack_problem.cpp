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
	
	
	return ans;
}
