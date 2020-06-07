// @hritikkumar

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; // namespace created as std
int minimizingSums(int*, int , int);
int main(void)
{
	std::ios::sync_with_stdio(false); 
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	int n;
	cin>>n;
	int* arr = new int[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int c; 
	cin>>c; //  c is power
	/* Optimal answer is ans = (sum of all numbers) / (no of numbers);
	 * We next consider a problem where we are given n numbers a 1 , a 2 , . . . , a n and our
	task is to find a value x that minimizes the sum
	| a 1 − x | c + | a 2 − x | c + · · · + | a n − x | c .
	We focus on the cases c = 1 and c = 2.
	 */
	 /*
	 This result can be derived by
	presenting the sum as follows:
	nx 2 − 2 x ( a 1 + a 2 + · · · + a n ) + ( a 21 + a 22 + · · · + a 2 n )
	The last part does not depend on x , so we can ignore it. The remaining parts
	form a function nx 2 − 2 xs where s = a 1 + a 2 + · · · + a n . This is a parabola opening
	upwards with roots x = 0 and x = 2 s / n , and the minimum value is the average of
	the roots x = s / n , i.e., the average of the numbers a 1 , a 2 , . . . , a n . 
	  * */	
	int ans = minimizingSums(arr, n,c);
	cout<<ans<<endl;	
	return 0; // return type is int
}
int minimizingSums(int *a, int n, int c)
{
	if(c==1)
	{
		sort(a, a+n);
		int median = a[n/2];
		int minSum = 0;
		for(int i = 0; i<n; i++)
			minSum += abs( a[i] - median);
		cout<<"MinSum: "<<minSum<<endl;
		return median;
	}
	else if(c==2)
	{
		int average = accumulate(a, a+n, 0) / n;
		int minSum = 0;
		for(int i = 0; i<n; i++)
		{
			minSum += abs( (a[i] - average) * (a[i]-average));
		}
		cout<<"MinSum: "<<minSum<<endl;
		return average;
	}
	else 
	{
		int sum = accumulate(a, a+n, 0); 
		int average = sum/n;
		int minSum = 0;
		for(int i = 0; i<n; i++)
		{
			minSum += abs ( pow( (a[i] - average) , c));
		}
		cout<<"MinSum: "<<minSum<<endl;
		return minSum;
	}
}
