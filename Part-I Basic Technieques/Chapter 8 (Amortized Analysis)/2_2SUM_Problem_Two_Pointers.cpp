// @hritikkumar

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; // namespae created as std

int TwoPointers2SUM(vector<int> &, int, int);

int main(void)
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	int sum;
	cin>>sum;
	
	int ans = TwoPointers2SUM(a, n, sum);
	cout<<ans<<endl;
	
	return 0; // return type is int
}

int TwoPointers2SUM(vector<int> &a, int n, int sum)
{
	sort(a.begin(), a.end());
	int i = 0, j = a.size() -1, ans = 0;
	while(i<j)
	{
		if((a[i] + a[j]) == sum)
		{
			ans +=1;
			i+=1;
			j-=1;
		}
		else if((a[i] + a[j]) > sum)
			j-=1;
		else
			i+=1;
	}
	return ans;
}
