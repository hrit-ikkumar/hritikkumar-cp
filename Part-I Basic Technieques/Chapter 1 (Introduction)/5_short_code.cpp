// @hritikkumar
#include<bits/stdc++.h> // all header files
using namespace std; //namespace created as std

// typedefing of the data types
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;


// Macros
#define F first
#define S second
#define PB push_back
#define MP make_pair

int main(void)
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	long long int  a = 1e-9; // a = 10^-9
	double x = 0.3*0.3 + 1;
	printf("%d\n%.20f\n", a,x); // floating point precision 
	
	ll val = 1e+18;
	printf("%d\n", val);
	vector<pi> vpi;
	vpi.PB(MP(a, val));
	int d = vpi[0].F + vpi[0].S;
	return 0; //return type is int
	
}
