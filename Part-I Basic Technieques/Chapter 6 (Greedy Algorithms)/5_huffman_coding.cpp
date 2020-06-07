// @hritikkumar
#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; //namespace created as std

// user defined data type for node
struct Node {
	char data;
	unsigned freq;
	struct Node* left, *right;
};


int main(void)
{
	std::ios::sync_with_stdio(false);  cin.tie(0); // fastio
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout); 
	#endif
	
	return 0; // return type is int
}
