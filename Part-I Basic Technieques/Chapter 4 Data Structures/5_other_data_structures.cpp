// @hritikkumar

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std;

int main(void)
{
	std::ios::sync_with_stdio(false); cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	// Bitset is a data structure which has two values either 0 or 1. It is like an array.
	bitset<10> bs;
	cin>>bs;
	// or bitset<10> bs(string("1010101010")); // 
	// print the bitset
	cout<<bs<<endl;
	cout<<bs[1]<<endl;
	// you can count all the even parity by using count method
	cout<<bs.count()<<endl;
	
	return 0; // return type is int
}
