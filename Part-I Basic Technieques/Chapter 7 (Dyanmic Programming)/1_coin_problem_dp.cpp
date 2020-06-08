// @hritikkumar

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; // namespace created as std

long long int dpMinCoinEfficientWithCoins( vector<long long int>, long long int, long long int); // dynamic programming solution by using memorization

long long int dpMinCoinEfficient( vector<long long int>, long long int, long long int); // dynamic programming solution by using memorization

long long int dpMinCoin( vector<long long int>, long long int, long long int, vector<long long int> &, vector<bool> &); // dynamic programming solution by using memorization

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
	
	// dp arrays
	vector<long long int> dp_table(amount+1, 0); // real values
	vector<bool> dp_ready(amount +1, false); // weather, we have calculated the values or not 
	cout<<"Minimum Coins: "<<dpMinCoin(coins, n, amount, dp_table, dp_ready)<<endl;
	cout<<"Minimum Coins: "<<dpMinCoinEfficient(coins, n, amount)<<endl;
	cout<<"Minimum Coins: "<<dpMinCoinEfficientWithCoins(coins, n, amount)<<endl;
	
	return 0; // return type is int  
}

long long int dpMinCoinEfficientWithCoins(vector<long long int> coins, long long int n, long long int amount)
{
	vector<long long int> dp_table(amount+1, 0);
	vector<long long int> first(amount +1, 0);
	
	dp_table[0] = 0;
	for(int x = 1; x <= amount; ++x)
	{
		dp_table[x] = INT_MAX;
		for(auto c : coins)
		{
			if( (x - c) >= 0 && dp_table[x-c] + 1 < dp_table[x])
			{
				dp_table[x] = dp_table[x-c] + 1;
				first[x] = c;
			}
		}
	}
	
	while(amount>0)
	{
		cout<<first[amount]<<" ";
		amount-= first[amount];
	}
	cout<<endl;
	
	return dp_table[amount];
}


long long int dpMinCoinEfficient(vector<long long int> coins, long long int n, long long int amount)
{
	vector<long long int> dp_table(amount+1, 0);
	dp_table[0] = 0;
	for(int x = 1; x <= amount; ++x)
	{
		dp_table[x] = INT_MAX;
		for(auto c : coins)
		{
			if( (x - c) >= 0)
				dp_table[x] = min(dp_table[x], dp_table[x-c] + 1);
		}
	}
	
	return dp_table[amount];
}

long long int dpMinCoin(vector<long long int> coins, long long int n, long long int amount, vector<long long int> &dp_table, vector<bool> &dp_ready)
{
	if(amount < 0 )
		return INT_MAX;
	else if(amount == 0)
		return 0; 
	else if(dp_ready[amount]) 
		return dp_table[amount];
	
	long long int best = INT_MAX;
	for(auto x : coins)
	{
		best = min (best , dpMinCoin(coins, n, amount - x, dp_table, dp_ready) + 1);
	}
	dp_table[amount] = best, dp_table[amount] = true;
	return best;
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
