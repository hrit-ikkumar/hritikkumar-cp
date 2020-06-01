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
	
	// Stack is a data structure which supports last in first out (LIFO) it has functions like push, pop, top 
	stack<int> st;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int val;
		cin>>val;
		st.push(val);
	}
	cout<<st.top()<<endl;
	cout<<st.size()<<endl;
	for(int i=0;i<n;i++)
		st.pop();
	cout<<st.size()<<endl;
	return 0; //return type is int
}
