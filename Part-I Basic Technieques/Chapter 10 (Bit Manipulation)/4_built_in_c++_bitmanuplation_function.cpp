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
	
	/*
	• __builtin_clz ( x ): the number of zeros at the beginning of the number
	• __builtin_ctz ( x ): the number of zeros at the end of the number
	• __builtin_popcount ( x ): the number of ones in the number
	• __builtin_parity ( x ): the parity (even or odd) of the number of ones
	*/
	
	int num;
	cin>>num;
	cout<< __builtin_clz(num)<<endl; // number of zeros at the beginning of the number
	cout<< __builtin_ctz(num)<<endl; // number of zeros at the end of number
	cout<< __builtin_popcount(num)<<endl; // number of 1's in number
	cout<< __builtin_parity(num)<<endl; // the parity (even or odd) of the number of ones ingiven number
	
	return 0; // return type is int
}
