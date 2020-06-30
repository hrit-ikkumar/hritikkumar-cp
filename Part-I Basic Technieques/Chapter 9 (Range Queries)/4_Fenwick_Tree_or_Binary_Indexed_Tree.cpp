// @hritikkumar

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; // namespace created as std

void fenwickAdd(vector<int> &, int , int );

int fenwickSum(vector<int> &, int );

int fenwickTreeBIT(vector<int>&, int , int , int);

int main(void)
{
	std::ios::sync_with_stdio(false); // fastio
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	int left, right;
	cin>>left>>right;
	
	int ans = fenwickTreeBIT(a, n, left, right);
	cout<<ans<<endl;
	return 0; // return type is int
}

// here x is only change in that value means (new_vaule - old_value)
void fenwickAdd(vector<int> &fenwick_table, int k, int x)
{
	while(k<=(signed)fenwick_table.size())
	{
		fenwick_table[k]  += x;
		k += k&-k;
	}
}

int fenwickSum(vector<int> &fenwick_table, int k)
{
	int sum = 0;
	while(k>=1)
	{
		sum += fenwick_table[k];
		k -= k&-k;
	}
	return sum;
}

int fenwickTreeBIT(vector<int> &a, int n, int left,int right)
{
	vector<int> fenwick_table(n+1, 0);
	for(int i=0;i<n;i++)
		fenwickAdd(fenwick_table, i+1,a[i]);
	int ans = fenwickSum(fenwick_table, right) - fenwickSum(fenwick_table, left -1);
	return ans;
}
