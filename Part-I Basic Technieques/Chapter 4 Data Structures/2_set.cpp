// @hritikkumar

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; 

int main(void)
{
	std::ios::sync_with_stdio(false); cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w",stdout);
	#endif
	
	set<int> st;
	int n;
	cin>>n;
	int val;
	for(int i=0;i<n;i++)
	{
		cin>>val;
		st.insert(val);
	}
	for(auto it: st)
	{
		cout<<it<<" ";
	}
	cout<<endl;
}
