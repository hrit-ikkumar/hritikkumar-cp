// @hritikkumar

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; // namespace created as std

int segmentSum(vector<int> &, int, int,int);

void segmentAdd(vector<int> &, int , int , int );

int segmentTreeSum(vector<int> &, int , int ,int );

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
	int ans = segmentTreeSum(a, n, left, right);
	cout<<ans<<endl; 
	return 0; // return type is int
}

int segmentSum(vector<int> &segmentTree, int n, int left, int right)
{
	left += n, right += n;
	int sum = 0;
	while(left <= right)
	{
		if(left%2 == 1) sum += segmentTree[left++];
		if(right%2 == 0) sum += segmentTree[right--];
		left>>=1, right>>=1;
	}
	return sum;
}

void segmentAdd(vector<int> &segmentTree, int n, int k, int x)
{
	k+=n, segmentTree[k] += x;
	for(k>>=1; k>=1; k/=2) 
		segmentTree[k] = segmentTree[2*k] + segmentTree[2*k + 1];
}

int segmentTreeSum(vector<int> &a, int n, int left, int right)
{
	vector<int> segmentTree(2*n+1, 0);
	for(int i=0;i<n;i++)
		segmentAdd(segmentTree, n, i+1, a[i]);
	return segmentSum(segmentTree, n, left, right);
}
