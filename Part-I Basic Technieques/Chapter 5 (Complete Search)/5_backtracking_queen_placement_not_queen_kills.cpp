// @hritikkumar

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; //namespace created as std  

void backTrackNQ(long long &, int,int,  int * &, int * &, int * &);

long long backtrackingNQueenPlacment(int );

int main(void)
{
	std::ios::sync_with_stdio(false); cin.tie(0);
	
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w",stdout);
	#endif
	
	int n;
	cin>>n;
	long long ans = backtrackingNQueenPlacment(n);
	
	cout<<ans<<endl;
	
	return 0; // return type is int 
}

void backTrackNQ(long long &count, int queens, int n, int* &	col, int * &diag1, int *&diag2)
{
	if(queens == n)
	{
		count++;
		return;
	}
	
	for(int x = 0; x<n;x++)
	{
		if(col[x] || diag1[x+queens] || diag2[x-queens + n-1]) continue;
		
		col[x] = diag1[x+queens] = diag2[x-queens+n-1] = 1;
		
		backTrackNQ(count, queens+1, n, col, diag1, diag2);
		
		col[x] = diag1[x+queens] = diag2[x-queens+n-1] = 0;
	}
}

long long backtrackingNQueenPlacment(int n)
{
	long long count = 0;
	int* col = new int[n];
	for(int i=0;i<n;i++) col[i] = 0;
	int *diag1 = new int[2*n];
	for(int i=0;i<2*n;i++) diag1[i] =0;
	int *diag2 = new int[2*n];
	for(int i=0;i<2*n;i++)diag2[i] = 0;
	
	backTrackNQ(count, 0,n,col, diag1, diag2);
	return count; // count is the answer of number of possible ways
	
}

