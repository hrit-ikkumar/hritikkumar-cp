// @hritikkumar

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; // namespace created as std

int nearestSmallestElement(vector<int> &, int);

int main(void)
{
	std::ios::sync_with_stdio(false); // fastio
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	
	int ans = nearestSmallestElement(a, n);
	cout<<ans<<endl;
	return 0; // return type is int 
}

int nearestSmallestElement(vector<int> &a, int n)
{
	stack<int> stk;
	for(int i=0;i<n;i++)
	{
		while(!stk.empty() && stk.top() >= a[i])
			stk.pop();
		stk.push(a[i]);
	}
	return stk.top();
}
