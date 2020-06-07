// @hritikkumar

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; // namespace created as std

long long int recMinCoin(vector<long long int> , long long int, long long int); // recursive function (less efficient)

 int main(void)
{
	std::ios::sync_with_stdio(false); cin.tie(0); // fastio
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout);
	#endif
	
	long long int n; // no of coins
	cin>>n;
	vector<long long int> coins(n, 0); 
	for(long long int i=0;i<n;i++) cin>>coins[i];
	long long int amount;
	cin>>amount;
	cout<<"Minimum Coins: "<<recMinCoin(coins, n, amount)<<endl;
	
	return 0; // return type is int  
}

long long int recMinCoin(vector<long long int> coins, long long int n, long long int amount)
{
	if(amount < 0)
		return INT_MAX; 
	else if(amount == 0)
		return 0; 
	
	long long int best = INT_MAX;
	
	for(auto x: coins) 
		best = min ( best, recMinCoin(coins, n, amount - x) + 1);
	
	return best;
}
