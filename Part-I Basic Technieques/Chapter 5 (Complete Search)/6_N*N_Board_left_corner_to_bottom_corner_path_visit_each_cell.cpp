// @hritikkumar

#include<bits/stdc++.h> // al header files

#define endl '\n'

using namespace std; //namespace created as std 

int backtracking(int**, int , int , int, int);

long long int calculateNoOfWays(int);
int ittr = 0;
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
	
	
	cout<<"ITR: "<<ittr<<endl;
	return 0; //return type is int
}
/*
 This is 6 X 6 board
 
____________________
|__||__||__||__||__||__|
|__||__||__||__||__||__|
|__||__||__||__||__||__|
|__||__||__||__||__||__|
|__||__||__||__||__||__|
|__||__||__||__||__||__| 
	*/
	
int backtracking(int **a ,int n, int i, int j , int cells)
{
	if( i< 0 || j < 0 || i > n-1 || j > n-1 || a[i][j] == 1  || (i==n-1 && j==n-1 && cells != n*n-1))
		return 0;
	a[i][j] = 1;
	cells +=1;
	 if(i== n-1 && j==n-1 &&  cells == n*n)
	{
		cells +=1;
		a[i][j] = 1;
		cout<<i<<" +++ "<<j<<endl;
		a[i][j] = 0;
		return 1;
	}
	cout<<endl;
	for(int row=0;row<n;row++)
	{
		for(int col=0; col < n; col++)
		{
			cout<<a[row][col]<<" ";
		}
		cout<<endl;
	}
	ittr++;
	cout<<endl;
	int left = backtracking(a, n, i-1, j, cells);
	int up = backtracking(a, n, i, j-1,cells );
	int down = backtracking(a, n, i, j+1,cells);
	int right = backtracking(a, n, i + 1, j, cells);
	a[i][j] = 0;
	return left + up +right + down;
}
long long int calculateNoOfWays(int n)
{
	int** board = new int*[n];
	for(int i=0;i<n;i++) board[i] = new int[n];
	
	for(int i=0;i<n;i++)for(int j=0;j<n;j++) board[i][j] = 0;
	// 0 mean not visited and 1 means that It has been visited!
	long long int ans = backtracking(board, n, 0, 0, 0);
	return ans; //return type is long long int
}
