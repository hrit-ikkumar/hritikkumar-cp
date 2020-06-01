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
	
	// queue is first in first out (FIFO) 
	// It supports functions like push front pop
	queue<int> q;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int val;
		cin>>val;
		q.push(val);
	}
	cout<<q.front()<<endl;
	cout<<q.size()<<endl;
	while(!q.empty())
	{
		q.pop();
	}
	cout<<q.size()<<endl;
	
	return 0; 
}
