// @hritikkumar

#include<bits/stdc++.h> // al header files

#define endl '\n'

using namespace std; //namespace created as std 

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
long long int calculateNoOfWays(int n)
{
	int* board = new int*[n];
	for(int i=0;i<n;i++) board[i] = new int[n];
	
	for(int i=0;i<n;i++)for(int j=0;j<n;j++) board[i][j] = 0;
	
	
	
}
