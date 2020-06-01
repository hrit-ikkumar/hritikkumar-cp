// @hritikkumar

#include<bits/stdc++.h> // al header files

#define endl '\n'

using namespace std; //namespace created as std 

void backtrackingLeftTopToBottomRight(int*, int , int , int , long long int &);

long long int calculateNoOfWays(int);

int main(void)
{
	std::ios::sync_with_stdio(false); cin.tie(0); // fastio
	#ifndef ONLINE_JUDGE
	freopen("input.txt" ,"r", stdin); 
	freopen("output.txt" , "w", stdout); 
	#endif
	
	int n;
	cin>>n;
	
	long long int ans = calculateNoOfWays(n); 
	cout<<ans<<endl;
	
	return 0; //return type is int
}
/*
 * This is 6 X 6 board
							________________________
						->|_|_||_|_||_|_||_|_||_|_||_|_|
							|_|_||_|_||_|_||_|_||_|_||_|_|
							|_|_||_|_||_|_||_|_||_|_||_|_|
							|_|_||_|_||_|_||_|_||_|_||_|_|
							|_|_||_|_||_|_||_|_||_|_||_|_|
							|_|_||_|_||_|_||_|_||_|_||_|_| <-
	*/
	
void backtrackingLeftTopToBottomRight(int *a int n, int i, int j , long long int &ans)
{
	 // backtracking function goes here
	 if(i== n-1 && j==n-1 && a[i][j] == 0)
	{
		a[i][j] = 0;
		ans +=1;
		return;
	}
	
	if(i > 1 && j > 1)
	{
		backtrackingLeftTopToBottomRight(a, 
	}
}
long long int calculateNoOfWays(int n)
{
	int* board = new int*[n];
	for(int i=0;i<n;i++) board[i] = new int[n];
	
	for(int i=0;i<n;i++)for(int j=0;j<n;j++) board[i][j] = 0;
	// 0 mean not visited and 1 means that It has been visited!
	long long int ans = 0;
	backtrackingLeftTopToBottomRight(a, n, 0, 0, ans);
	return 0; //return type is long long int
}
