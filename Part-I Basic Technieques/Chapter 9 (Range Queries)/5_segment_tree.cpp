// @hritikkumar

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; // namespace created as std

// Segment Tree for Sum
int segmentSum(vector<int> &, int, int,int);

void segmentAdd(vector<int> &, int , int , int );

int segmentTreeSum(vector<int> &, int , int ,int );


// Segment Tree for Max
int segmentMax(vector<int> &, int, int,int);

void segmentAddMax(vector<int> &, int , int , int );

int segmentTreeMax(vector<int> &, int , int ,int );

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
	// this segment tree is for sum, we can also implement for min or max
	int ans = segmentTreeSum(a, n, left, right);
	cout<<ans<<endl; 
	ans = segmentTreeMax(a, n, left, right);
	cout<<ans<<endl;
	return 0; // return type is int
}

// Segment Tree for Sum
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


// Segment Tree for Maximum in array 

int segmentMax(vector<int> &segmentTree, int n, int left, int right)
{
	left += n, right += n;
	int maxi = 0;
	while(left <= right)
	{
		if(left%2 == 1) maxi = max(maxi,segmentTree[left++]);
		if(right%2 == 0) maxi = max(maxi, segmentTree[right--]);
		left>>=1, right>>=1;
	}
	return maxi;
}

void segmentAddMax(vector<int> &segmentTree, int n, int k, int x)
{
	k+=n, segmentTree[k] += x;
	for(k>>=1; k>=1; k/=2) 
		segmentTree[k] = max(segmentTree[2*k] , segmentTree[2*k + 1]);
}

int segmentTreeMax(vector<int> &a, int n, int left, int right)
{
	vector<int> segmentTree(2*n+1, 0);
	for(int i=0;i<n;i++)
		segmentAddMax(segmentTree, n, i+1, a[i]);
	return segmentMax(segmentTree, n, left, right);
}
