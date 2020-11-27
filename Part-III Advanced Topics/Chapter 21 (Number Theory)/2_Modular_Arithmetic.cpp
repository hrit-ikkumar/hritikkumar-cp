#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; // namespace created as std

/*
 * Modular Arithmetic
( x + y ) mod m = ( x mod m + y mod m ) mod m
( x − y ) mod m=( x mod m − y mod m ) mod m
( x · y ) mod m=( x mod m · y mod m ) mod m
x n mod m=( x mod m ) n mod m
 */

class ModularArithmetic
{
	public:
		ModularArithmetic() {}
		
		int modularExponentiation(int x, int y, int mod)
		{
			if(y==0)
				return 1 % mod;
			long long int half = modularExponentiation(x, y/2, mod);
			
			long long int full = (half  * half ) % mod;
			
			if(y % 2 == 1)
				full = (full * x) % mod;
			
			return full;
		}
};

int main(void)
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); // fastio
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w" ,stdout);
	#endif
	
	ModularArithmetic *ma = new ModularArithmetic();
	int num1, num2, md;
	cin>>num1>>num2>>md;
	cout<< (ma -> modularExponentiation(num1, num2,md)) <<endl;
	
	return 0; // return type is int
}
