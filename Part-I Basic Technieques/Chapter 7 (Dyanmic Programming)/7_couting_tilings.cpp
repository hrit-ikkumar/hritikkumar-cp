// @hritikkumar

#include<bits/stdc++.h> // all header files

#define endl '\n'
#define pi 3.14
typedef long long ll;
typedef long double ld;
using namespace std; // namespace created as std

void helperFunc(int , int, int , int, ll**, int , int);

ll countingTilingsDP(int , int , int , int);

ll countingTilingsMath(int , int , int , int);

int main(void)
{
	std::ios::sync_with_stdio(false); cin.tie(0); // fastio
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n, m;
	cin>>n>>m;
	int a , b;
	cin>>a>>b;
	ll ans = 0; // countingTilingsDP(n, m, a, b);
	ans = countingTilingsMath(n, m, a,b);
	
	cout<<ans<<endl;
	
	return 0; // return type is int
}
ll countingTilingsMath(int n, int m, int a, int b)
{
	ld ans = 1;
	for(int i = 1; i<= ceil(n/2); ++i)
	{
		for(int j = 1 ; j<=ceil(m/2); ++j)
		{
			ans *= (ld)4 * ( cos((ld)(pi * i) / (n+1)) * cos((ld)(pi * i) / (n+1)) + cos((ld)(pi * j) / (m+1))*cos((ld)(pi * j) / (m+1)) );
		}
	}
	return (ll)ans;
}


void helperFunc(int x, int y , int mask, int next_mask , ll** dp_table, int n, int m)
{
	if(x==n)
		return;
	if(y >= m)
		dp_table[x+1][next_mask] += dp_table[x][mask];
	else
	{
		int my_mask = 1 << y;
		if(mask & my_mask)
			helperFunc(x, y+1, mask, next_mask,dp_table, n,m);
		else
		{
			helperFunc(x, y+1, mask, next_mask | my_mask, dp_table, n, m);
			if(y+1 <m && !(mask & my_mask) && !(mask & (my_mask <<1)))
				helperFunc(x, y+2, mask, next_mask, dp_table, n, m);
		}
	}
}

ll countingTilingsDP(int n, int m, int a, int b)
{
	ll** dp_table = new ll*[n];
	for(int i=0;i<n;i++) dp_table[i] = new ll[ 1<<m];
	for(int i=0;i<n;i++) for(int j= 0; j<(1<<m);j++) dp_table[i][j] = 0;
	dp_table[0][0] = 1;
	for(int x =0; x<n;++x)
	{
		for(int mask = 0;mask<(1<<m); ++mask)
		{
			helperFunc(x, 0, mask, 0, dp_table, n, m);
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j = 0;j<(1<<m);++j)
			cout<<dp_table[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
	return dp_table[n][0];
}
