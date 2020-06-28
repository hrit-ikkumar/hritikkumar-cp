// @hritikkumar

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; // namespace created as std

vector<pair<int, int>> subarraySum(int*, int , int);

int main(void)
{
	std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0); // fastio
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin>>n;
	int* a = new int[n];
	int sum = 0;
	cin>>sum; 
	
	for(int i=0;i<n;i++) cin>>a[i]; // array
	
	vector<pair<int, int>> ans = subarraySum(a, n, sum);
	cout<<ans.size()<<endl;
	for(pair x: ans)
		cout<<x.first<<" "<<x.second<<endl;
	cout<<endl;
	return 0; // return type is int
}

vector<pair<int, int>> subarraySum(int *a, int n, int sum)
{
	vector<pair<int,int>> res;
	int left, right, currSum;
	int count = 0;
	for(int i =0 ;i<n; i++)
	{
		if(a[i] == sum)
			count++;
	}
	for(left=0, right =0, currSum=0;left<n && right<n ; left+=1)
	{
		while(right<n && (currSum + a[right]) <= sum)
		{
			currSum += a[right];
			right +=1;
		}
		if( currSum == sum)
		{
			res.push_back({left, right-1});
		}
		currSum -= a[left];
	}
	return res;
}
