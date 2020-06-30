// @hritikkumar

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; // namespace created as std

int main(void)
{
	std::ios::sync_with_stdio(false); // fastio
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int num;
	cin>>num;
	unsigned int unsigned_num = num;
	cout<<num<<endl<<unsigned_num<<endl;
	int val;
	cin>>val;
	cout<<val<<endl;
	val++;
	cout<<val<<endl;
	return 0; // return type is int 
}
