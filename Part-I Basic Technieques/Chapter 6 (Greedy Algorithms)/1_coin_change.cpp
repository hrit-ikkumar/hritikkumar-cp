// @hritikkumar
#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; // namespace created as std

int maximumCoins(int*, int , int); // maximumCoins

int main(void)
{
	std::ios::sync_with_stdio(false); cin.tie(0); // fastio
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	int n;
	cin>>n;
	int* coins = new int [n];
	for(int i=0;i<n;i++)cin>>coins[i];
	int money;
	cin>>money;
	// sort the coins
	sort(coins, coins + n); // sorted
	
	cout<<maximumCoins(coins, n, money)<<endl;
	return 0; //return type is int
}

int maximumCoins(int *coins, int n, int money)
{
	int ans = 0;
	int i = n - 1;
	while(i>=0 && money > 0)
	{
		ans += money / coins[i];
		money -= (money/ coins[i]) * coins[i];
		i--;
	}
	
	return ans; 
}
