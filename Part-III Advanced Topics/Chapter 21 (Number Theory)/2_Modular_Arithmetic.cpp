#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; // namespace created as std

/*
 * Modular Arithmetic
( x + y ) mod m = ( x mod m + y mod m ) mod m
( x − y ) mod m=( x mod m − y mod m ) mod m
( x · y ) mod m=( x mod m · y mod m ) mod m
x^n mod m=( x mod m ) ^ n mod m
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
		// Naive approach, always work 
		int modularInverseNaive(int x, int mod)
		{
			x = x % mod;
			for(int n = 1; n < mod; n++)
			{
				if( (x * n) % mod == 1)
					return n;
			}
		}
		
		// Extended Euclidean Algorithm when x and mod are co prime
		int modInverseEuclidExtended(int x, int mod)
		{
			int a, b;
			int g = gcdExtended(x, mod, &a, &b);
			int res = -1;
			if(g == 1)
			{
				cout<<"GCD Doesn't Exist"<<endl;
			}
			else
			{
				res = (a % mod + mod) % mod;
				cout<<"Modular multiplicative inverse is "<<res<<endl;
			}
			return res;
		}
		
		int gcdExtended(int a, int b, int* x, int* y) 
		{ 
			// Base Case 
			if (a == 0)  
			{ 
				*x = 0, *y = 1; 
				return b; 
			} 
		  
			int x1, y1; // To store results of recursive call 
			int gcd = gcdExtended(b % a, a, &x1, &y1); 
		  
			// Update x and y using results of recursive 
			// call 
			*x = y1 - (b / a) * x1; 
			*y = x1; 
		  
			return gcd; 
		}
		// iterative version
		int modInverse(int a, int mod)
		{
			int m0 = mod;
			int y = 0, x = 1;
			
			if(mod == 1)
				return 0;
			
			while(a>1)
			{
				int q = a / mod;
				int t = mod;
				
				y = x - q * y;
				x = t;
			}
			
			if(x < 0)
				x += m0;
			
			return x;
		}
		
		// Fermat's Theorem when m is prime 
		int modInverseFermat(int a, int mod)
		{
			int g = __gcd(a, mod);
			if(g!=1)
				cout<<"inverse doesn't exist";
			else
			{
				return (int)pow(a, mod -2) % mod;
			}
			return -1;
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
