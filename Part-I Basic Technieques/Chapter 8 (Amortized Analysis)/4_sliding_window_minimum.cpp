// @hritikkumar

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; // namespace created as std

vector<int> slidingWindowMinimumK(vector<int> &, int , int );

int main(void)
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	int window;
	cin>>window;
	
	vector<int> ans = slidingWindowMinimumK(a, n, window);
	for(int x: ans)
		cout<<x<<" ";
	cout<<endl;
	
	return 0; // return type is int
}

vector<int> slidingWindowMinimumK(vector<int> &a, int n, int k)
{
	vector<int> ans;
	deque<int> dq;
	for(int i=0;i<k;i++)
	{
		while(!dq.empty() && a[dq.back()] > a[i])	dq.pop_back();
		dq.push_back(i);
	}
	ans.push_back(a[dq.front()]);
	for(int i=k;i<n;i++)
	{
		while(!dq.empty() && dq.front() <= i-k) dq.pop_front();
		while(!dq.empty() && a[dq.back()] > a[i])	dq.pop_back();
		dq.push_back(i);
		ans.push_back(a[dq.front()]);
	}
	return ans;
}
