// @hritikkumar

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; // namespace created as std

vector<int> subarraySum(int*, int , int);

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
	
	vector<int> ans = subarraySum(a, n, sum);
	for(int x: ans)
		cout<<x<<" ";
	cout<<endl;
	return 0; // return type is int
}

vector<int> subarraySum(int *a, int n, int sum)
{
	vector<int> res;
	int left, right, currSum;
	left = 0, right = 1, currSum = a[left];
	int count = 0;
	for(int i =0 ;i<n; i++)
	{
		if(a[i] == sum)
			count++;
	}
	while(left < n -1 && right < n)
	{
		currSum += a[right];
		if(currSum == sum )
			count+=1;
		right +=1;
		if(right == n)
		{
			left +=1;
			right = left +=1;
			currSum = a[left];
			continue;
		}
	}
	for(int i = left, j = right;i<=j;i++)
	{
		res.push_back(a[i]);
	}
	return res;
}
