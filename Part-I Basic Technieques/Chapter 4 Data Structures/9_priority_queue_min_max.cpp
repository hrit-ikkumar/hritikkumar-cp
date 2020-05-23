// @hritikkumar

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; //namespace created as std

int main(void)
{
	std::ios::sync_with_stdio(false); cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	// priority queue is based on the sorted kind of stuff based on the particular value
	// max heap
	priority_queue<int>  pq;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int val;
		cin>>val;
		pq.push(val);
	}
	cout<<pq.top()<<endl;
	cout<<pq.size()<<endl;
	while(!pq.empty())
	{
		pq.pop();
	}
	cout<<pq.size()<<endl;
	
	// min heap can be declared through this way
	priority_queue<int, vector<int>, greater<int>> min_pq;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int val;
		cin>>val;
		min_pq.push(val);
	}
	cout<<min_pq.top()<<endl;
	cout<<min_pq.size()<<endl;
	while(!min_pq.empty())
	{
		min_pq.pop();
	}
	cout<<min_pq.size()<<endl;
	return 0; 
}
