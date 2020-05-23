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
	
	// deque supports four operations pust_front, pop_front & push_back, pop_back
	// front, back for getting the front and back element in this ds
	deque<int> dq;
	int n;
	cin>>n;
	int val; 
	for(int i=0;i<n;i++)
	{
		cin>>val;
		dq.push_back(val);
		dq.push_front(val);
	}
	cout<<dq.front()<<" "<<dq.back()<<endl;
	cout<<dq.size()<<endl;
	for(int i=0;i<n;i++)
	{
		dq.pop_back();
		dq.pop_front();
	}
	cout<<dq.size()<<endl;
	// Average time complexity of each operation is O(1).. to be noted it's average. 
	// deque is a dynamic array so, whenever we reach to maximum limit we have to resize the array
	
	return 0; //return type is int
}
