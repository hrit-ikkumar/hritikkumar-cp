// @hritikkumar

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; // namespace created as std

long long int dpCountPossibleCoinCombinations(vector<int>, int , int );

int main(void)
{
	std::ios::sync_with_stdio(false); cin.tie(0); // fastio
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout); 
	#endif
	
	int n;
	cin>>n;
	vector<int> coins(n);
	for(int i=0;i<n;i++)cin>>coins[i];
	int amount;
	cin>>amount;
	cout<<"Counts: "<<dpCountPossibleCoinCombinations(coins, n , amount)<<endl;
	return 0; 
}

long long int dpCountPossibleCoinCombinations(vector<int> coins, int n, int amount)
{
	vector<int> count(amount+1, 0);
	count[0] = 1;
	
	for(int x = 1; x<=amount; ++x)
	{
		for(auto c: coins)
		{
			if( (x-c) >= 0)
			{
				count[x] += count[x-c];
				/* if the answer is too big
				 * and the question asked for only mod value
				 * count[x] += count[x-c] % mod;
				 * count[x] %= mod;
				 */
			}
		}
	}
	return count[amount];
}
