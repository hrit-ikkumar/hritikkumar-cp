// @hritikkumar

#include<bits/stdc++.h> // all header files

#define endl '\n'

typedef long long ll;

using namespace std; // namespace created as std

ll countingTilingsDP(int , int , int , int);

int main(void)
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); // fastio
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n, m;
	cin>>n>>m;
	int a , b;
	cin>>a>>b;
	
	ll ans = countingTilingsDP(n, m, a, b);
	
	cout<<ans<<endl;
	
	return 0; // return type is int
}


ll countingTilingsDP(int n, int m, int a, int b)
{
	
}
