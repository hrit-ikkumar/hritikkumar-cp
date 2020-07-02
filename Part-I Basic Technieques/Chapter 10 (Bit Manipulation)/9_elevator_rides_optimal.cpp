// @hritikkumar

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; // namespace created as std

int elevatorRidesOptimal(vector<pair<int,int>> &, int ,int);

int main(void)
{
	std::ios::sync_with_stdio(false); // fastio
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	int x, n; cin>>x>>n;
	vector<pair<int, int>> a(n);
	for(int i=0;i<n;i++) cin>>a[i].first>>a[i].second;
	int ans = elevatorRidesOptimal(a, n, x);
	cout<<ans<<endl;
	
	return 0; // return type is int
}

int elevatorRidesOptimal(vector<pair<int, int>> &a, int n, int x)
{
	vector<pair<int, int>> best(1<<n);
	best[0] = {1,0};
	for(int s = 1;s<(1<<n);s++)
	{
		best[s] = {n+1, 0};
		for(int p = 0;p<n;p++)
		{
			if(s&(1<<p))
			{
				auto option = best[s^(1<<p)];
				if(option.second + a[p].second <= x)
					option.second += a[p].second;
				else
					option.first++, option.second = a[p].second;
				best[s] = min(best[s], option);
			}
		}
	}
	return best[(1<<n)-1].first;
}
